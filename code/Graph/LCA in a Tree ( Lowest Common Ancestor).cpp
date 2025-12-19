#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e5+5;
vector < int > tree[N];
int par[N];

void dfs(int vertex, int parent = -1) {
  par[vertex] = parent;
  for(int child : tree[vertex]) {
    if(child == parent) continue;
    dfs(child,vertex);
  }
}
vector < int > path(int vertex) {
  vector < int > ans;
  while(vertex != -1) {
    ans.push_back(par[vertex]);
    vertex = par[vertex];
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
signed main() {
  int v; cin >> v;
  for(int i = 0; i < v-1; i++) {
    int x,y; cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  
  dfs(1);
  int x,y; cin >> x >> y;
  vector < int > x_par = path(x);
  vector < int > y_par = path(y);
  int len = min(x_par.size(),y_par.size());
  int lca = -1;
  
  for(int i = 0; i < len; i++) {
    if(x_par[i] == y_par[i]) {
      lca = x_par[i];
    }
    else {
      break;
    }
  }
  cout << "Lowest common ancestor : " << lca << endl;
}
