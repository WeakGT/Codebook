// g is O(log^6 n).
// Runtime is O(ans * log phi(n) * log n), which is approximately O(log^8 n).
// #define int long long
int fp(int a, int b, int p) {
  int ret = 1;
  for (; b; b >>= 1, a = a * a % m)
    if (b & 1) ret = ret * a % m;
  return ret;
}

int generator(int p) {
  vector<int> fact;
  int phi = p - 1,  n = phi;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  if (n > 1) fact.push_back (n);

  for (int res = 2; res <= p; ++res) {
    bool ok = true;
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= fp(res, phi / fact[i], p) != 1;
    if (ok)  return res;
  }
  return -1;
}