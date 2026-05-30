//a^p-1 == 1 ( mod p)
// mulmod -> calculate the large values liks 2^63-1 mod
lli mulmod(lli a, lli b , lli c) {
   int x = 0, y = a % c;
   while(b) {
      if(b&1) {
         x = (x + y) % c;
      }
      y = (y * 2ll) % c;
      b >>= 1;
   }
   return x % c;
}
lli bigMod(int a, int b, int mod) {
   lli res = 1;
   while(b) {
      if(b&1) {
         res = mulmod(res,a,mod);
      }
      a = mulmod(a,a,mod);
      b>>=1;
   }
   return res;
}
bool isprime(int n, int itr = 5) {
   if(n < 4) {
      return n == 2 or n == 3;
   }
   for(int i = 1; i <= itr; i++) {
      lli a = 2 + rand() % (n-3);
      lli res = bigMod(a,n-1,n);
      if(res != 1) {
         return false;
      }
   }
   return true;
}