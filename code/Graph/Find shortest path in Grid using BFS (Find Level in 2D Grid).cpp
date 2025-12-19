#include "bits/stdc++.h"
#define int long long
using namespace std;

const int INF = 1e9+10;
int level[8][8];
int vis[8][8];

void reset() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      level[i][j] = INF;
      vis[i][j] = 0;
    }
  }
}
bool isValid(int x, int y) {
  return (x >= 0 and y >= 0 and x < 8 and y < 8);
}
vector < pair<int,int> > movements = {
  {1,2},{-1,2},
  {2,1},{2,-1},
  {-2,1},{-2,-1},
  {1,-2},{-1,-2}
};

int getX(string &a) {
  return a[0] - 'a';
}

int getY(string &a) {
  return a[1] - '1';
}

int bfs(string &source, string &dest) {

  reset();
  int sourceX = getX(source);
  int sourceY = getY(source);
  int destX = getX(dest);
  int destY = getY(dest);
  queue < pair<int,int> > q;
  q.push({sourceX,sourceY});
  vis[sourceX][sourceY] = 1;
  level[sourceX][sourceY] = 0;

  while(!q.empty()) {
    auto v = q.front();
    int x = v.first;
    int y = v.second;
    q.pop();
    for(auto move : movements) {
      int childX = move.first + x;
      int childY = move.second + y;
      if(!isValid(childX, childY)) continue;
      if(!vis[childX][childY]) {
        
        q.push({childX,childY});
        vis[childX][childY] = 1;
        level[childX][childY] = level[x][y] + 1;
      }
    }
    if(level[destX][destY] != INF) {
      break;
    }
  }
  return level[destX][destY];
}

signed main () {
  string s1,s2; cin >> s1 >> s2;
  cout << bfs(s1,s2) << endl;
}
