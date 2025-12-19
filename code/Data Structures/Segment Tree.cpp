#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e6+7;
int segTree[4*N];
int n;
int ar[N];
void buildTree(int i, int l, int r){
  if(l == r) {
    segTree[i] = ar[r]; return;
  }
  int mid = l + (r - l) / 2;
  buildTree(2*i+1,l,mid);
  buildTree(2*i+2,mid+1,r);
  segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void updateSegTree(int index, int val, int i = 0, int l = 0, int r = n - 1) {
  if(l == r) {
    segTree[i] = val; return;
  }
  int mid = l + (r - l) / 2;
  if(index <= mid) updateSegTree(index,val,2*i+1,l,mid);
  else updateSegTree(index,val,2*i+2,mid+1,r);
  segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int Querry(int start, int end, int i = 0, int l = 0, int r = n - 1) {
  if(l > end or r < start ) return 0;
  if(l >= start and r <= end ) return segTree[i];
  else {
    int mid = l + (r - l)/2;
    return Querry(start,end,2*i+1,l,mid) + Querry(start,end,2*i+2,mid+1,r);
  }
}

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  buildTree(0,0,n-1);
  int k; cin >> k;
  while(k--) {
    char u; cin >> u;
    int l,r; cin >> l >> r;
    if(u == 'u') {
      updateSegTree(l,r);
      continue;
    }
    cout << Querry(l,r) << endl;
  }
}
signed main()
{   
  int tt = 1;
  while(tt--)
  solve();
}
