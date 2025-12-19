#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 3e5+5;
vector < int > tree[N];
int ar[N];
int dp1[N];
int ans[N];
int n,k,q;
void clear(int n) {
    for(int i = 0; i <= n; i++) {
      tree[i].clear();
      ar[i] = 0;
      ans[i] = 0;
      dp1[i] = 0;
    }
}
void pre(int vertex, int par) {
    dp1[vertex] = 0;
    for(auto child : tree[vertex]) {
      if(child == par) continue;
      pre(child,vertex);
      dp1[vertex] = max(dp1[vertex],dp1[child]);

    }
    dp1[vertex] += ar[vertex];
}
void reroot(int vertex, int par, int max_val) {
    ans[vertex] = max(dp1[vertex],max_val+ar[vertex]);
    int maxi = 0, low = 0;
    for(auto child : tree[vertex]) {
      if(child == par) continue;
      int val = dp1[child];
      if(val > maxi) {
            low = maxi;
            maxi = val;
      }
      else if(val > low) {
            low = val;
      }
    }
    for(auto child : tree[vertex]) {
      if(child == par) continue;
      int x = (dp1[child] == maxi) ? low : maxi;
      int boro = max(max_val,x) + ar[vertex];

      reroot(child,vertex,boro);
    }
}
void solve()
{
    cin >> n >> k >> q;
    clear(n);
    for(int i = 1; i <= k; i++) {
      int x; cin >> x;
      ar[x] = 1;
    }
    for(int i = 1; i < n; i++) {
      int u,v; cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    vector < int > qr;
    while(q--) {
      int x; cin >> x;
      qr.push_back(x);
    }
    pre(1,-1);
    reroot(1,-1,0);
    int maxi = 0;
    for(int i = 1; i <= n; i++) {
      maxi = max(maxi,ans[i]);
    }
    for(auto &it:qr) {
      if(ans[it] == maxi) cout << "JA" << endl;
      else cout << "NEIN" << endl;
    }
}
signed main()
{ 
    ios_base::sync_with_stdio(0),cin.tie(0); 
    int tt = 1;
    cin >> tt;
    while(tt--)
    solve();
}
