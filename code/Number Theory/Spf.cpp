const int MAXN = 1e6 + 2;
int spf[MAXN];
vector<int> prms;
void preStore() {
  for (int i = 1; i < MAXN; i++) spf[i] = i;
  for (int i = 2; i < MAXN; i++) {
    if (spf[i] == i) {
      prms.push_back(i);
      for (int j = i + i; j < MAXN; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}
