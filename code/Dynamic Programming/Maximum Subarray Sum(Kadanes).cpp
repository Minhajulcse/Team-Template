int max_sum_of(vector<int> &vct){
  int mx = INT_MIN, till = 0;
  for (int i = 0; i<vct.size(); i++) {
    till = till + vct[i];
    mx = max(mx, till);
    till = max(till, 1LL*0);
  }
  return mx;
}
