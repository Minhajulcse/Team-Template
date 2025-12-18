const int mod = 1e9+7;
void solve(){
  int n, k; cin>>n>>k;
  vector<int> coin(n);
  for(int i = 0; i<n; i++){ cin>>coin[i];  }
  vector<int> dp(k+1, 0); dp[0] = 1;
  for(int i = 1; i<=k; i++){
    for(int j = 0; j<n; j++){  
      if(i-coin[j]>=0){ 
        dp[i] = (dp[i]+dp[i-coin[j]])%mod;
      } 
    }
  } cout<<dp[k]<<endl;
}


