const int N = 1e5+5;

vector < int > tree[N];
int depth[N], height[N];

bool dfs(int vertex, int parent = -1) {
  
  for(int child : tree[vertex]) {
    if(child == parent) continue;
    
    depth[child] = depth[vertex] + 1;
    dfs(child,vertex);
    height[vertex] = max(height[vertex], height[child] + 1);
  }
}
