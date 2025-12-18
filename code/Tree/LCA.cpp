const int N = 1e5 + 5;
vector<int> g[N], parent(N), depth(N, 0);
void dfs(int vertex, int par = -1) {
  parent[vertex] = par;
  for (auto child : g[vertex]) {
    if (child != par) {
        depth[child] = depth[vertex] + 1;  dfs(child, vertex);
    }
  }
}
int lca(int x, int y) {
  int diff = min(depth[x], depth[y]);
  while (depth[x] > diff) x = parent[x];
  while (depth[y] > diff) y = parent[y];
  while (x != y) { x = parent[x]; y = parent[y]; }  return x;
}
