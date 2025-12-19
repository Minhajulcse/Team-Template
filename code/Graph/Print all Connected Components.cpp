#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e5+5;
vector < int > g[N];
bool vis[N];
vector < vector < int > > cc;
vector < int > current_cc;

void dfs(int vertex) {
    vis[vertex] = true;
    current_cc.push_back(vertex);
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
    for(int i = 1; i <= v; i++) {
      if(vis[i] == true) continue;
      current_cc.clear();
      dfs(i);
      cc.push_back(current_cc);
    }
    cout << "Total connected componenets : " << cc.size() << endl;
    for(auto u:cc) {
      for(int vertex : u) {
        cout << vertex << " ";
      }
      cout << endl;
    }
}
