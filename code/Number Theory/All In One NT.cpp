const int MAXN = 1e6 + 9;
typedef struct info {
  int lowest_prime = 0, greatest_prime = 0, distinct_prime = 0;
  int total_prime = 0, NOD = 0, SOD = 0;
} info;
info num[MAXN];
void preStore() {
  for (int i = 2; i < MAXN; i++) {
    int n = i;
    map<int, int> factors;  // Key->Factor, Val->count
    int SOD = 1, NOD = 1, total_p_factor = 0;
    if (n % 2 == 0) {
      while (n % 2 == 0) {
        n /= 2;
        factors[2]++;
        total_p_factor++;
      }
      SOD *= (1 << (factors[2] + 1)) - 1;
      NOD *= (factors[2] + 1);
    }
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        while (n % i == 0) {
          n /= i;
          factors[i]++;
          total_p_factor++;
        }
        SOD *= (pow(i, factors[i] + 1) - 1) / (i - 1);
        NOD *= (factors[i] + 1);
      }
    }
    if (n > 1) {
      factors[n]++;
      SOD *= (pow(n, 2) - 1) / (n - 1);
      NOD *= 2;
      total_p_factor++;
    }
    num[i].distinct_prime = factors.size();
    num[i].total_prime = total_p_factor;
    num[i].NOD = NOD;
    num[i].SOD = SOD;
    auto lowest_prime = factors.begin();
    auto greatest_prime = factors.rbegin();
    num[i].lowest_prime = lowest_prime->first;
    num[i].greatest_prime = greatest_prime->first;
  }
}