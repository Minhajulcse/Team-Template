#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int segTree[4*N];
int lazy[4*N];
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
int Querry(int start, int end, int i = 0, int l = 0, int r = n - 1) {
  if(lazy[i] != 0) {
    segTree[i] += (r-l+1) * lazy[i];
    if(l != r) {
      lazy[2*i+1] += lazy[i];
      lazy[2*i+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(l > end or r < start ) return 0;
  if(l >= start and r <= end ) return segTree[i];
  else {
    int mid = l + (r - l)/2;
    return Querry(start,end,2*i+1,l,mid) + Querry(start,end,2*i+2,mid+1,r);
  }
}
// LAZY PROPAGATION
void updateRange(int start, int end, int val, int i = 0, int l = 0, int r = n -1) {
  if(lazy[i] != 0) {
    segTree[i] += (r-l+1) * lazy[i];
    if(l != r) {
      lazy[2*i+1] += lazy[i];
      lazy[2*i+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  // out of range
  if(l > end or r < start or l > r) return;
  // in the range
  if(l >= start and r <= end) {
    segTree[i] += (r-l+1) * val;
    if(l != r) {
      lazy[2*i+1] += val;
      lazy[2*i+2] += val;
    }
    return;
  }
  // overlapping
  int mid = l + (r - l)/2;
  updateRange(start,end,val,2*i+1,l,mid);
  updateRange(start,end,val,2*i+2,mid+1,r);
  segTree[i] = segTree[2*i+1] + segTree[2*i+2];
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
    char x; cin >> x;
    if(x == 'R') {
      int l , r, val; cin >> l >> r >> val;
      updateRange(l,r,val);
      continue;
    }
    else if(x == 'X') {
      int l , r; cin >> l >> r;
      cout << Querry(l,r) << endl;
    }
  }
}
signed main()
{   
  int tt = 1;
  while(tt--)
  solve();
}
