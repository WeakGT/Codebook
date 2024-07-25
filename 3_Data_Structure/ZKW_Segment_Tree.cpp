const int N = 5e5 + 5;
int a[N];

struct seg_tree { // 0-based
  int seg[N << 1], n;
  void upd(int x, int v) {
    for (seg[x += n] = v; x > 1; x >>= 1)
      seg[x >> 1] = max(seg[x], seg[x ^ 1]);
  }
  int qry(int l, int r) { // [ql, qr]
    int ret = -1e9;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret = max(ret, seg[l++]);
      if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
  }
  void init(int _n) {
    n = _n;
    copy(a, a + n, seg + n);
    for (int i = n - 1; i >= 0; i--)
      seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
  }
} tree;
// tree.init(n)
// tree.qry(l - 1, r - 1)