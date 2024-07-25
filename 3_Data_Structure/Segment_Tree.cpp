const int N = 2e5 + 5;
int a[N];

struct seg_tree {
  ll seg[N << 2], tag[N << 2];
  void pull(int id) {
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }
  void push(int id, int l, int r) {
    if (tag[id]) {
      int m = (l + r) >> 1;
      seg[id << 1] += tag[id] * (m - l + 1);
      seg[id << 1 | 1] += tag[id] * (r - m);
      tag[id << 1] += tag[id];
      tag[id << 1 | 1] += tag[id];
      tag[id] = 0;
    }
  }
  void build(int l, int r, int id = 1) {
    if (l == r) {
      seg[id] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, id << 1), build(m + 1, r, id << 1 | 1);
    pull(id);
  }
  void upd(int ql, int qr, int v, int l, int r, int id = 1) {
    if (ql <= l && r <= qr) {
      seg[id] += 1LL * (r - l + 1) * v;
      tag[id] += v;
      return;
    }
    push(id, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) upd(ql, qr, v, l, m, id << 1);
    if (qr > m) upd(ql, qr, v, m + 1, r, id << 1 | 1);
    pull(id);
  }
  ll qry(int ql, int qr, int l, int r, int id = 1) {
    if (ql <= l && r <= qr) return seg[id];
    push(id, l, r);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (ql <= m) ret += qry(ql, qr, l, m, id << 1);
    if (qr > m) ret += qry(ql, qr, m + 1, r, id << 1 | 1);
    return ret;
  }
  void init(int n) {
    fill_n(seg, 0, n << 2), fill_n(tag, 0, n << 2);
  }

} tree;
// tree.init(n)
// tree.build(1, n)
// tree.upd(ql, qr, v, 1, n)
// tree.qry(ql, qr, 1, n)