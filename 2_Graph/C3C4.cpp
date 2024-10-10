#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, M;
  cin >> N >> M;

  vector<int> deg(N);
  vector<array<int, 2>> e(M);
  for (auto &[u, v] : e) {
    cin >> u >> v;
    --u, --v;
    ++deg[u], ++deg[v];
  }

  vector<int> ord(N), rk(N);
  iota(all(ord), 0);
  sort(all(ord), [&](int x, int y) { return deg[x] > deg[y]; });
  for (int i = 0; i < N; i++) rk[ord[i]] = i;

  vector<vector<int>> D(N), adj(N);
  for (auto [u, v] : e) {
    if (rk[u] > rk[v]) swap(u, v);
    D[u].emplace_back(v);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> vis(N);

  int64_t c3 = 0, c4 = 0;
  // ord = sort by deg decreasing, rk[ord[i]] = i
  // D[i] = edge point from rk small to rk big
  for (int x : ord) { // c3
    for (int y : D[x]) vis[y] = 1;
    for (int y : D[x]) for (int z : D[y]) c3 += vis[z];
    for (int y : D[x]) vis[y] = 0;
  }
  for (int x : ord) { // c4
    for (int y : D[x]) for (int z : adj[y])
      if (rk[z] > rk[x]) c4 += vis[z]++;
    for (int y : D[x]) for (int z : adj[y])
      if (rk[z] > rk[x]) --vis[z];
  } // both are O(M*sqrt(M)), test @ 2022 CCPC guangzhou

  cout << c4 * 8 << '\n';
}