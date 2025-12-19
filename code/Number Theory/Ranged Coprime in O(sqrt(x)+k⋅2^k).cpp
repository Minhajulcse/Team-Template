//Prime factorization of x: O(√x)
//Inclusion–Exclusion: O(2^k)
//(k ≤ 9 for x ≤ 10⁹)
#include <bits/stdc++.h>
using namespace std;
/* get distinct prime factors of x */
vector<long long> prime_factors(long long x) {
    vector<long long> primes;
    for (long long i = 2; i * i <= x; i++) {
      if(x % i == 0) {
            primes.push_back(i);
            while (x % i == 0) x /= i;
      }
    }
    if (x > 1) primes.push_back(x);
    return primes;
}
/* count numbers in [1..n] coprime with x */
long long coprime_upto(long long n, long long x) {
    if (n <= 0) return 0;
    vector<long long> p = prime_factors(x);
    int k = p.size();
    long long res = n;
    // Inclusion-Exclusion over subsets
    for (int mask = 1; mask < (1 << k); mask++) {
        long long prod = 1;
        int bits = 0;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                prod *= p[i];
                bits++;
            }
      }
      if (bits % 2 == 1)
            res -= n / prod;
      else
            res += n / prod;
    }
    return res;
}
int main() {
    long long l, r, x;
    cin >> l >> r >> x;
    cout << coprime_upto(r, x) - coprime_upto(l - 1, x);
    return 0;
}