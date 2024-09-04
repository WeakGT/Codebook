const int MAXN = 1e5 + 5;
int n, q, vis[MAXN], sz[MAXN];
vector<int> adj[MAXN], pa[MAXN], mx[MAXN], dis[MAXN];

void dfs_sz(int x, int p) {
    sz[x] = 1;
    for (int i : adj[x]) {
        if (i == p or vis[i]) continue;
        dfs_sz(i, x);
        sz[x] += sz[i];
    }
}
int cen;
void dfs_cen(int x, int p, int all) {
    int tmp = all - sz[x];
    for (int i : adj[x]) {
        if (i == p or vis[i]) continue;
        dfs_cen(i, x, all);
        chmax(tmp, sz[i]);
    }
    if (tmp * 2 <= all) cen = x;
}
void dfs(int x, int p, int d) {
    pa[x].pb(cen);
    dis[x].pb(d);
    if (d >= mx[cen].size()) mx[cen].pb(x);
    else chmax(mx[cen][d], x);
    for (int i : adj[x]) {
        if (i == p or vis[i]) continue;
        dfs(i, x, d + 1);
    }
}
void deco(int x, int d) {
    dfs_sz(x, x);
    dfs_cen(x, x, sz[x]);
    vis[cen] = 1;
    dfs(cen, cen, 0);
    for (int i = 1; i < mx[cen].size(); i++) {
        chmax(mx[cen][i], mx[cen][i - 1]);
    }
    for (int i : adj[cen]) {
        if (vis[i]) continue;
        deco(i, d + 1);
    }
}
int get(int x, int k) {
    if (!mx[x].size() or k < 0) return 0;
    return k >= mx[x].size() ? mx[x].back() : mx[x][k];
}
int query(int x, int k) {
    int res = get(x, k);
    for (int i = 0; i < pa[x].size(); i++) {
        int p = pa[x][i];
        int d = dis[x][i];
        chmax(res, get(p, k - d));
    }
    return res;
}

signed main() {
    WOSHAOJI
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    deco(1, 0);
    while (q--) {
        int x, k; cin >> x >> k;
        cout << query(x, k) << '\n';
    }
}