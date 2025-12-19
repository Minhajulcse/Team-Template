bool dfs(int vertex, int parent) {

    vis[vertex] = true;
    bool isLoopExist = false;
    
    for(auto child : g[vertex]) {
      if(vis[child] == true and child == parent) continue;
      if(vis[child] == true) return true;
        isLoopExist = isLoopExist | dfs(child, vertex);
    }
    return isLoopExist;
}
