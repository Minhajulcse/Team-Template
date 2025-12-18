//1st problem
const ll mod = 1e9+7;
void solution(){
  ll n; cin>>n;
  ll i = 1;
  ll l = 0, r = 0;
  ll sum = 0;
  while(i<=n){
    ll p = n/i;
    ll l = i-1;
    i = (n/p)+1;
    ll r;
    if(i<=n){
      r = i-1;
    }
    else{
      r = n;
    }
    ll s1 = (__int128(l)*(l+1)/2)%mod;
    ll s2 = (__int128(r)*(r+1)/2)%mod;
    // cout<<l<<" "<<r<<" "<<s1<<' '<<s2<<endl;
    sum = ((sum%mod) + (((s2-s1+mod)%mod)*(p%mod))%mod)%mod;
  }
  cout<<sum<<endl;
}

//2nd problem
void solution(){
  ll n; cin>>n;
  vector<ll> v;
  ll i = 1;
  ll sum = 0;
  while(i<=n){
    ll p = n/i;
    ll prev = i;
    v.push_back(p);
    i = (n/p)+1;
    ll q;
    if(i<=n){
      q = i-prev;
    }
    else{
      q = n-prev+1;
    }
    sum+=p*q;
  }
  cout<<sum<<endl;
}
