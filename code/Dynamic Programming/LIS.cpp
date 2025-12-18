vector<int> lis(int n, vector<int>& v) {
  vector<int> parent(n, -1), ind(n);
  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
    if (it == lis.size()) {
      lis.push_back(v[i]);
      ind[lis.size() - 1] = i;
      parent[i] = (lis.size() == 1 ? -1 : ind[it - 1]);
    } else {
      lis[it] = v[i];
      ind[it] = i;
      parent[i] = (it == 0 ? -1 : ind[it - 1]);
    }
  }
  vector<int> LIS;
  int it = ind[lis.size() - 1];
  LIS.push_back(lis.back());
  while (parent[it] != -1) {
    it = parent[it];
    LIS.push_back(v[it]);
  }
  return LIS;
}