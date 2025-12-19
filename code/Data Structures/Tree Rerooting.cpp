#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector < int > tree[N];
vector < int > subtree_sum(N,1);
vector < int > dist(N,0);
int ans[N];
int ar[N];
int n;

void pre(int vertex, int par) {

    subtree_sum[vertex] = ar[vertex];
    for(auto child : tree[vertex]) {
      if(child == par) continue;
      pre(child,vertex);
      dist[vertex] += dist[child] + subtree_sum[child];
      subtree_sum[vertex] += subtree_sum[child];
    }
}

void reroot(int vertex, int par) {
    ans[vertex] = dist[vertex];
    for(auto child : tree[vertex]) {
      if(child == par) continue;

      dist[vertex] -= (dist[child] + subtree_sum[child]);
      subtree_sum[vertex] -= subtree_sum[child];

      dist[child] += (dist[vertex] + subtree_sum[vertex]);
      subtree_sum[child] += subtree_sum[vertex];

      reroot(child,vertex);

      dist[child] -= (dist[vertex] + subtree_sum[vertex]);
      subtree_sum[child] -= subtree_sum[vertex];

      dist[vertex] += (dist[child] + subtree_sum[child]);
      subtree_sum[vertex] += subtree_sum[child];
    }
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for(int i = 1; i < n; i++) {
      int u,v; cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    pre(1,-1);
    reroot(1,-1);
    int maxi = 0;
    for(int i = 1; i <= n; i++) {
      maxi = max(maxi,ans[i]);
    }
    cout << maxi << endl;
}
signed main()
{ 
    int tt = 1;
    while(tt--)
    solve();
}
