const int N = 2e5 + 5;
int n, a[N];

struct BIT { // 1-based
  ll bit1[N], bit2[N];
  ll sum(ll* bit, int x) {
    ll ret = 0;
    for (; x; x -= x & -x) ret += bit[x];
    return ret;
  }
  void upd(ll* bit, int x, ll v) {
    for (; x <= n; x += x & -x) bit[x] += v;
  }
  ll qry(int x) {
    return (x + 1) * sum(bit1, x) - sum(bit2, x);
  }
  ll qry(int l, int r) { // [l, r]
    return qry(r) - qry(l - 1);
  }
  void upd(int l, int r, ll v) { // [l, r]
    upd(bit1, l, v), upd(bit2, l, l * v);
    upd(bit1, r + 1, -v), upd(bit2, r + 1, (r + 1) * -v);
  }
  BIT() {
    fill_n(bit1, N, 0), fill_n(bit2, N, 0);
  }
  BIT(int* a) { // O(n) build
    fill_n(bit1, N, 0), fill_n(bit2, N, 0);
    for (int i = 1; i <= n; i++) bit1[i] = a[i] - a[i - (i & -i)];
    for (int i = n; i; i--) a[i] -= a[i - 1];
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + a[i] * i;
    for (int i = 1; i <= n; i++) bit2[i] = a[i] - a[i - (i & -i)];
  }
};