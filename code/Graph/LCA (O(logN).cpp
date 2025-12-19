#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;   // since 2^20 > 2e5
vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int n;

/* DFS to build depth[] and up[][] */
void dfs(int v, int p) {
    up[v][0] = p;  // immediate parent
    for (int i = 1; i < LOG; i++) {
      up[v][i] = up[ up[v][i-1] ][i-1];
    }
    for (int to : adj[v]) {
      if (to == p) continue;
      depth[to] = depth[v] + 1;
      dfs(to, v);
    }
}

/* Find LCA of u and v */
int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);
    // 1️⃣ Bring u and v to same depth
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
      if (diff & (1 << i))
            u = up[u][i];
    }

    if (u == v) return u;
    // 2️⃣ Lift both nodes up until parents differ
    for (int i = LOG - 1; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
      }
    }
    // 3️⃣ Parent is LCA
    return up[u][0];
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    depth[1] = 0;
    dfs(1, 0);   // root at node 1
    int q;
    cin >> q;
    while (q--) {
      int u, v;
      cin >> u >> v;
      cout << lca(u, v) << "\n";
    }
}