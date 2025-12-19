#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9+7;
const int N = (int)1e5+10;
vector < int > tree[N];
int val[N];
int subtree_sum[N];

void dfs(int vertex, int parent = -1) {
  subtree_sum[vertex] += val[vertex];
  for(int child : tree[vertex]) {
    dfs(child,vertex);
    subtree_sum[vertex] += subtree_sum[child] + 0LL;
  }
}
int main() 
{
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> val[i];
  
  dfs(1);
  int maxi = 0;
  for(int i = 2; i <= n; i++) {
    int sum1 = subtree_sum[i];
    int sum2 = subtree_sum[1] - sum1;
    maxi = max(maxi,(sum1*sum2*1LL) % mod);
  }
  cout << "Maximum sum possible : " << maxi << endl;
}
