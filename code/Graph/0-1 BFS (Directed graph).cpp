#include "bits/stdc++.h"
#define int long long
using namespace std;

const int INF = 1e9 + 10;
const int N = 1e5+10;
vector < int > level(N,INF);
vector < pair<int,int> > g[N];
int n,m;

int bfs() {
  deque < int > q;
  q.push_back(1);
  level[1] = 0;

  while(!q.empty()) {
    int cur_v = q.front();
    q.pop_front();

    for(auto child : g[cur_v]) {
      int child_v = child.first;
      int wt = child.second;
      if(level[cur_v] + wt < level[child_v]) {
        level[child_v] = level[cur_v] + wt;
        if(wt == 0) {
          q.push_front(child_v);
        }
        else q.push_back(child_v);
      }
    }
  }
  return level[n] == INF ? -1 : level[n];
}
signed main()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x,y; cin >> x >> y;
    if(x == y) continue;
    g[x].push_back({y,0});
    g[y].push_back({x,1});
  }

  cout << bfs() << endl;
}
