#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5;
vector < int > g[N];
int n,m;
int deg[N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
      int u,v; cin >> u >> v;
      g[u].push_back(v);
      deg[v]++;
    }
    queue < int > q;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 0) {
          q.push(i);
      }
    }
    while(!q.empty()) {
      auto vertex = q.front(); q.pop();
      cout << vertex<< " ";
      for(auto child : g[vertex]){
          deg[child]--;
          if(deg[child] == 0) q.push(child);
      }
    }
    cout << endl;
}
signed main()
{ 
    ios_base::sync_with_stdio(0),cin.tie(0); 
    int tt = 1;
    while(tt--)
    solve();
}