const int N = 1e5+5;

vector < int > tree[N];

int subtreeSum[N];
int evenCount[n], oddCount[N];

void dfs(int vertex, int parent = -1) {
  
  subtreeSum[vertex] += vertex;
  if(vertex % 2 == 0) {
    evenCount[vertex] += 1;
  }
  else {
    oddCount[vertex] += 1;
  }
  for(int child : tree[vertex]) {
    
    if(child == parent) continue;
    
    dfs(child,vertex);
    
    subtreeSum[vertex] += subtreeSum[child];
    evenCount[vertex] += evenCount[child];
    oddCount[vertex] += oddCount[child];
  }
}
