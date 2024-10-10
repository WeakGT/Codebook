// O(VE)
struct Maximum_cardinality_matching {
  int n, k;
  int match[1005]; //right
  int vis[1005]; // left
  vector<int> adj[1005]; // left
  int dfs(int x) {
    vis[x] = 1;
    for (int i : adj[x]) {
      if (match[i] == -1 or (!vis[match[i]] and dfs(match[i]))) {
        match[i] = x;
        return true;
      }
    }
    return false;
  }
  int paired[1005];
  int vis2[1005];
  void dfs2(int x) {
    vis[x] = 1;
    for (int i : adj[x]) {
      if (!vis2[i]) {
        vis2[i] = 1;
        dfs2(match[i]);
      }
    }
  }
  void matching() {
    fill(match + 1, match + 1 + k, -1);
    int res = 0;
    FOR (i, 1, k) {
      fill(vis + 1, vis + 1 + k, 0);
      res += dfs(i);
    }
    FOR (i, 1, k) {
      if (match[i] != -1) {
        paired[match[i]] = 1;
      }
    }
    fill(vis + 1, vis + 1 + k, 0);
    fill(vis2 + 1, vis2 + 1 + k, 0);
    FOR (i, 1, k) {
      if (!paired[i]) {
        dfs2(i);
      }
    }
    vector<int> a, b;
    FOR (i, 1, k) {
      if (!vis[i]) a.pb(i);
      if (vis2[i]) b.pb(i);
    }
    cout << SZ(a) << ' ' << SZ(b) << '\n';
    for (int i : a) cout << i << ' '; cout << '\n';
    for (int i : b) cout << i << ' '; cout << '\n';
    assert(SZ(a) + SZ(b) == res);
  }