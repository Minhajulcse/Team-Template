void computeLPS(string &pat, int m, vi &lps) {
    int i = 1, j = 0;
    while(i<m) {
        if(pat[i] == pat[j]) {
            ++j;
            lps[i] = j;
            ++i;
        }
        else {
            if(j == 0) {
                lps[i] = 0;
                ++i;
            }
            else {
                j = lps[j-1];
            }
        }
    }
}
vi kmp(string &s, string &pat) {
    int m = pat.size();
    int n = s.size();
    vi lps(m,0);
    computeLPS(pat,m,lps);
    int i = 0, j = 0;
    vi ans;
    while(i < n) {
        if(s[i] == pat[j]) {
            ++i,++j;
        }
        if(j == m) {
            ans.pb(i-j+1);
            j = lps[j-1];
        }
        else if(s[i] != pat[j]) {
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                ++i;
            }
        }
    }
    return ans; // which point
}