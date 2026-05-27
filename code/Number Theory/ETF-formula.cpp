//phi(n) = n * (p1-1) *(p2-1) * (pn-1) / (p1*p2*p3*....pn)
// TC -> O(sqrt(n))
int phi(int n) {
      int res = n;
      for(int i = 2; i * i <= n; i++ ) {
            if(n % i == 0 ) {
                  res/= i;
                  res *= (i - 1);
                  while(n % i == 0)n/=i;
            }
      }
      if(n > 1) {
            res /= n;
            res *= (n - 1);
      }
      return res;
}