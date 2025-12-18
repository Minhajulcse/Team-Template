const ll MAXN = 1e7 + 10;
bool prime[MAXN];
vector<ll> prm;
void sieve() {
  prime[0] = prime[1] = true;
  for (ll i = 2; i < MAXN; i++) {
    if (!prime[i]) {
      prm.push_back(i);
      for (ll j = i + i; j < MAXN; j += i) {
        prime[j] = true;
      }
    }
  }
}
