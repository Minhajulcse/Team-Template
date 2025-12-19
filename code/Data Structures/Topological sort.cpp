#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5;
vector < int > g[N];
int vis[N];
int n,m;
stack < int > tmp;

void dfs(int vertex) {
    vis[vertex] = 1;
    for(auto child : g[vertex]) {
      if(vis[child]) continue;
      dfs(child);
    }
    tmp.push(vertex);
}
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
      int u,v; cin >> u >> v;
      g[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
      if(vis[i]) continue;
      dfs(i);
    }
    vector < int > ans;
    while(tmp.size()) {
      ans.push_back(tmp.top());
      tmp.pop();
    }
    for(auto &it:ans) cout << it << " ";
    cout << endl;
}
signed main()
{ 
    ios_base::sync_with_stdio(0),cin.tie(0); 
    int tt = 1;
    while(tt--)
    solve();
}
