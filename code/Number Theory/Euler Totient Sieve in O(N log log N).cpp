#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> phi(N + 1);
    // Step 1: Initialize
    for (int i = 1; i <= N; i++)
       phi[i] = i;

    // Step 2: Sieve
    for (int i = 2; i <= N; i++) {
      if (phi[i] == i) { // i is prime
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
      }
    }
    // Step 3: Output
    for (int i = 1; i <= N; i++) {
      cout << "phi(" << i << ") = " << phi[i] << "\n";
    }
    return 0;
}