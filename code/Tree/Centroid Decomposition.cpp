const int N = 2e5+5;
int n, k, sz[N], centered[N], ans = 0;
vector<int> adj[N];
void dfs_sz(int u, int p) {
  sz[u] = 1;
  for (auto v: adj[u]) {
    if (v != p && !centered[v]) {
      dfs_sz(v, u); sz[u] += sz[v];
    }
  }
}
int get_cen(int u, int p, int n) {
  for (auto v: adj[u]) {
    if (v != p && !centered[v] && sz[v] > n/2) {
      return get_cen(v, u, n);
    }
  } return u;
}
int t, tin[N], tout[N], nodes[N], dis[N];
void dfs(int u, int p){
  nodes[t] = u;
  tin[u] = t++;
  for(auto v: adj[u]){
    if(v!=p && !centered[v]){
      dis[v] = dis[u]+1; dfs(v, u);
    }
  } tout[u] = t-1;
}
void go(int u){
  dfs_sz(u, u);
  int c = get_cen(u, u, sz[u]);
  centered[c] = 1; sz[c] = sz[u];
  t = 0; dis[c] = 0; dfs(c, c);
  int cnt[t]{1};
  for(auto v: adj[c]){
    if(centered[v]) continue;
    for(int i = tin[v]; i<=tout[v]; ++i){
      int w = nodes[i];
      if(k-dis[w]>=0 && k-dis[w]<t){
        ans+=cnt[k-dis[w]];
      }
    }
    for(int i = tin[v]; i<=tout[v]; ++i){
      int w = nodes[i]; cnt[dis[w]]++;
    }
  }
  for(auto v: adj[c]){
    if(!centered[v]){  go(v); }
  }
}
void solve() {
  cin>>n>>k;
  for(ll i = 1; i<n; i++){
    ll u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } go(1);
  cout<<ans<<endl;
}
