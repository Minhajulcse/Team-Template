int cnt = 0;
for(int i = 1; i <= v; i++) {
  if(vis[i] == true) continue;
  dfs(i);
  ++cnt;
}
cout << cnt << endl;
