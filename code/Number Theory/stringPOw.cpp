// Calculates (a^b) % m where b is a large number in string format
long long stringPow(long long a, string b, long long m) {
    long long res = 1;
    a %= m;
    
    for (char c : b) {
        int digit = c - '0';
        
        // res = (res^10) % m
        long long res_to_10 = binpow(res, 10, m);
        
        // a_to_digit = (a^digit) % m
        long long a_to_digit = binpow(a, digit, m);
        
        // Combine them: res = (res^10 * a^digit) % m
        res = (res_to_10 * a_to_digit) % m;
    }
    
    return res;
}