vector < vector<int> > image;
int initialColor, newColor;

void dfs(int i, int j) {
  int row = image.size();
  int col = image[0].size();
  
  if(i < 0 or j < 0) return;
  if(i >= row or j >= col) return;
  if(image[i][j] != initialColor) return;
  
  image[i][j] = newColor;
  
  dfs(i+1,j);
  dfs(i-1,j);
  dfs(i,j+1);
  dfs(i,j-1);
}
