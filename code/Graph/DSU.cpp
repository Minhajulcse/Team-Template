#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int parent[N];
int size[N];

// make, find, union
void make(int v) {
  parent[v] = v;
  size[v] = 1;
}
int find (int v) {
  if(parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}
void Union(int a, int b) {
  a = find(a);
  b = find(b);
  if(a != b) {
    if(size[a] < size[b]) {
      swap(a,b);
    }
    parent[b] = a;
    size[a] += size[b];
  }
}
void solve()  {
  int n,k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    make(i);
  }
  cout << "Before union " << endl;
  for(int i = 1; i <= n; i++) {
    cout << "For " << i << ": " << parent[i] << endl;
  }
  while(k--) {
    int u,v; cin >> u >> v;
    Union(u,v);
  }
  int cnt = 0;
  cout << "After union " << endl;
  for(int i = 1; i <= n; i++) {
    if(parent[i] == i) ++cnt;
    cout << "For " << i << ": " << parent[i] << endl;
  }
  cout << cnt << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
