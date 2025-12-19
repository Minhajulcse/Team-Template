#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9 + 10;
const int N = 1e3+10;
int level[N][N];
int vis[N][N];
int g[N][N];
int n,m;

void reset() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      vis[i][j] = 0;
      level[i][j] = 9;
    }
  }
}
vector < pair < int, int > > movement = {
  {0,1},{0,-1},{1,0},{-1,0},
  {1,1},{1,-1},{-1,1},{-1,-1}
};
bool isValid(int x, int y) {
  return (x >= 0 and y >= 0 and x < n and y < m);
}

int bfs() {
  reset();
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      maxi = max(maxi,g[i][j]);
    }
  }
  queue < pair < int, int > > q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(g[i][j] == maxi) {
        q.push({i,j});
        level[i][j] = 0;
        vis[i][j] = 1;
      }
    }
  }
  int ans = 0;
  while(!q.empty()) {
    auto v = q.front(); q.pop();
    int x = v.first;
    int y = v.second;
    for(auto move : movement) {
      int child_x = move.first + x;
      int child_y = move.second + y;
      if(!isValid(child_x,child_y)) {
        continue;
      }
      if(vis[child_x][child_y]) continue;
      q.push({child_x,child_y});
      vis[child_x][child_y] = 1;
      level[child_x][child_y] = level[x][y] + 1;
      ans = max(ans,level[child_x][child_y]);
    }
  }
  return ans;
}
signed main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  cout << bfs() << endl;
}
