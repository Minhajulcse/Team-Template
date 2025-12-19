#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool vis[N];
int level[N];
std::vector<int> tree[N];

void bfs(int source) {
  queue < int > q;
  q.push(source);
  vis[source] = true;
  while(!q.empty()) {
    int cur_v = q.front(); q.pop();
    
    for(int child : tree[cur_v]) {
      if(vis[child] == false) {
        q.push(child);
        vis[child] = true;
        level[child] = level[cur_v] + 1;
      }
    }
  }
}
