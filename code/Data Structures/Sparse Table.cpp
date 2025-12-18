const int mxN = 1e5 + 10, M = 21;
int sparse[mxN][M];
void build_sparse(int n, vector<int>& v) {
  for (int i = 0; i < n; i++) sparse[i][0] = v[i];
  for (int k = 1; k < M; k++) {
    for (int i = 0; i + (1 << k) <= n; i++) {
      sparse[i][k] = max(sparse[i][k - 1], sparse[i + (1 << (k - 1))][k - 1]);
    }
  }
}
int query(int l, int r) {  // 0 based index
  if (l > r) swap(l, r);
  int b = __bit_width(r - l + 1) - 1;
  return max(sparse[l][b], sparse[r - (1 << b) + 1][b]);
}