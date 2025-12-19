int lp[1000001];
void factorization(int n) {
    for(int i = 2; i*i <= n; i++) {
      if(n%2==0) {
         int cnt = 0;
          while(n%2==0) {
            ++cnt;
            n /= 2;
          }
          cout << i << "^" << cnt << endl;
      }
     }
    if(n > 1) cout << n << "^" << 1 << endl;
}
