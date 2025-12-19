#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e5+5;
vector < int > tree[N];
int depth[N];

void dfs(int vertex, int parent = -1) {
  for(int child : tree[vertex]) {
    if(child == parent) continue;
    depth[child] = depth[vertex] + 1;
    dfs(child,vertex);
  }
}

signed main() {
  int v; cin >> v;
  for(int i = 0; i < v-1; i++) {
    int x,y; cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(1);
  
  int max_depth = -1;
  int max_vertex = -1;
  for(int i = 1; i <= v; i++) {
    if(max_depth < depth[i]) {
      max_depth = depth[i];
      max_vertex = i;
    }
    depth[i] = 0;
  }
  
  int diameter = -1;
  dfs(max_vertex);
  for(int i = 1; i <= n; i++) {
    diameter = max(diameter,depth[i]);
  } 
  cout << "Maximum diameter : " << diameter << endl;
  
}
