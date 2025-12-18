ll latticeInCircle(ll r){
  ll ans = (4*r) +1; // 1 for center
  for(int i = 1; i*i<=r*r; i++){
    for(int j = 1; j*j+i*i<=r*r; j++){  ans+=4;  }
  } return ans;
}
