int lp[1000001];
void sieve() {
    int maxN = 1000000;
    for(int i = 0; i <= maxN; i++) lp[i] = -1;
    for(int i = 2; i*i <= maxN; i++) {
      if(lp[i] ==-1) {
            for(int j = i; j <= maxN; j+=i) {
                if(lp[j] == -1) lp[j] = i;
            }
      }
    }
}
