#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
  // For Adjacency Matrix
  // SC -> O(V*V);
    int v,e; cin >> v >> e;
    int graph[n+1][n+1];
    
    for(int i = 0; i < e; i++) {
      int v1,v2; cin >> v1 >> v2;
      graph[v1][v2] = 1;
      graph[v2][v1] = 1;
    }
}
