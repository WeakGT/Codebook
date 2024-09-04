const int MAXN = 2e5 + 5;
int a[MAXN];

int sum[MAXN * 25], lc[MAXN * 25], rc[MAXN * 25];
int add_node() {
    static int now = 0;
    return ++now;
}
void pull(int x) {
    sum[x] = sum[lc[x]] + sum[rc[x]];
}
void init(int &x, int lx, int rx) {
    if (!x) x = add_node();
    if (lx + 1 == rx) return;
    int mid = (lx + rx) / 2;
    init(lc[x], lx, mid);
    init(rc[x], mid, rx);
}
void update(int fa, int &x, int lx, int rx, int i) {
    if (!x) x = add_node();
    if (lx + 1 == rx) return sum[x]++, void();
    int mid = (lx + rx) / 2;
    if (i < mid) {
        rc[x] = rc[fa];
        update(lc[fa] , lc[x], lx, mid, i);
    }
    else {
        lc[x] = lc[fa];
        update(rc[fa], rc[x], mid, rx, i);
    }
    pull(x);
}
int query(int x, int lx, int rx, int l, int r) {
    if (lx >= r or rx <= l) return 0;
    if (lx >= l and rx <= r) return sum[x];
    int mid = (lx + rx) / 2;
    return query(lc[x], lx, mid, l, r) + query(rc[x], mid, rx, l, r);
}