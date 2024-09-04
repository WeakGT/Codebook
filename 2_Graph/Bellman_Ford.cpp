struct edge{
  int u, v;
  int cost;
};
vector<int> d(n, inf);
bool bellman_ford(vector<edge> &ee, int n, int s){
  d[s] = 0;
  auto relax = [&](edge e){
    if(d[e.v] > d[e.u] + e.cost){
      d[e.v] = d[e.u] + e.cost;
      return 1;
    }
    return 0;
  }
  for(int t = 1; t <= n; ++t){
    bool update = 0;
    for(auto &e: ee)
      update |= relax(e);
    if(t == n && update) return 0;
  }
  return 1;
}