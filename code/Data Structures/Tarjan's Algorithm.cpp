#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 55;
vector<int> g[N];
vector<int>timee(N,0),low(N,0);
int vis[N];
int n,m;
int cnt = 0;
int timer = 1;
void dfs(int vertex, int par = -1) {
    vis[vertex] = 1;
    timee[vertex] = low[vertex] = timer;
    ++timer;
    for(auto child : g[vertex]) {
      if(child == par ) continue;
      if(vis[child] == 1 ) {
          low[vertex] = min(low[vertex],low[child]); continue;
      }
      dfs(child, vertex);
      low[vertex] = min(low[vertex],low[child]);
      if(low[child] > timee[vertex]) ++cnt;
    }
}
void solve()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int x,y; cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(1);
    cout << cnt << endl;
}
signed main()
{ 
    ios_base::sync_with_stdio(0),cin.tie(0); 
    int tt = 1;
   // cin >> tt;
    while(tt--)
    solve();
}
