vector<int> nmbrs;
int dp[10][10][2];
int dgt_dp(int idx, int tight, int onecnt) {
  if (idx == nmbrs.size()) {
    return onecnt;
  }
  if (dp[idx][onecnt][tight] != -1) return dp[idx][onecnt][tight];
  int lmt = (tight ? nmbrs[idx] : 9);
  int sum = 0;
  for (int i = 0; i <= lmt; i++) {
    bool newTight = (tight and i == nmbrs[idx]);
    sum += dgt_dp(idx + 1, newTight, onecnt + (i == 1));
  }
  return dp[idx][onecnt][tight] = sum;
}