const int mxN = 1e7+10;
vector<int> phi(mxN);
void phi_till() { //O(n.log.log(n))
  for (int i = 0; i < mxN; i++) phi[i] = i;
  for (int i = 2; i < mxN; i++) {
    if (phi[i] == i) {  
      for (int j = i; j < mxN; j += i){ 
        phi[j] -= phi[j] / i; 
      } 
    } 
  } 
}
