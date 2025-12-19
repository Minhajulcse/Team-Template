/*
1. Sum of Pair Sums
(n - 1) * Σ a[k]

2. Sum of Subarray Sums
Σ ( a[k] * k * (n - k + 1) )

3. Sum of Subset Sums
2^(n - 1) * Σ a[k]

4. Product of Pair Products
Π ( a[k]^(n - 1) )

5. XOR of Subarray XORs
⊕ { a[k] | k(n - k + 1) is odd }

6. Sum of Max - Min over all Subsets
Σ ( a[k] * (2^(k - 1) - 2^(n - k)) )

7. Sum of Sum*Length over all Subarrays
Σ ( a[k] * ( k(n - k + 1)(n + 1) / 2 ) )

8. Sum of Pair XORs
Σ ( cnt1(b) * cnt0(b) * 2^b )

9. Sum of Pair ANDs
Σ ( C(cnt1(b), 2) * 2^b )

10. Sum of Pair ORs
Σ ( (C(n, 2) - C(cnt0(b), 2)) * 2^b )

11. Sum of Subset XORs
Σ ( [cnt1(b) > 0] * 2^(n - 1) * 2^b )

12. Sum of Subset ANDs
Σ ( (2^(cnt1(b)) - 1) * 2^b )

13. Sum of Subset ORs
Σ ( (2^n - 2^(cnt0(b))) * 2^b )
*/