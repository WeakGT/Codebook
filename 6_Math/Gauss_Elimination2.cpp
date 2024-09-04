using ll = long long;
const ll mod = 998244353;
ll fp(ll a, ll b) {
  ll ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
vector<ll> gauss_elimination(vector<vector<ll>>& a) { // n * (n+1)
  // if a[i][j] < 0, a[i][j] += mod
  int n = a.size();
  bool swp = 0;
  for (int i = 0; i < n; i++) {
    for (int k = i; k < n; k++) {
      if (a[i][i] == 0 && a[k][i] != 0) {
        swap(a[i], a[k]), swp ^= 1; // det = -det
        break;
      }
    }
    if (a[i][i] == 0) return {}; // 0
    ll inv = fp(a[i][i], mod - 2);
    for (int j = 0; j < n; j++) {
      if (i != j) {
        ll tmp = a[j][i] * inv % mod;
        for (int k = i; k <= n; k++)
          a[j][k] = (a[j][k] - tmp * a[i][k] % mod + mod) % mod;
      }
    }
  }
  // general solution
  vector<ll> ans(n);
  for (int i = 0; i < n; i++) ans[i] = a[i][n] * fp(a[i][i], mod - 2) % mod;
  return ans;
  // det
  // ll ret = 1;
  // for (int i = 0; i < n; i++) ret = ret * a[i][i] % mod;
  // return swp ? mod - ret : ret;
}