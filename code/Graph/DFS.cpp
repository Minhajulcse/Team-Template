#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e5+5;
vector < int > g[N];
bool vis[N];

void dfs(int vertex) {
    cout << vertex << " ";
    vis[vertex] = true;
    for(auto child : g[vertex]) {
      if(vis[child] == true) continue;
      dfs(child);
    }
}
signed main() {
    int v,e; cin >> v >> e;
    for(int i = 0; i < e; i++) {
      int x,y; cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(1);
    cout << endl;
}
