void multiply(vector <vector <int>>&mat1, vector <vector <int>>&mat2) {
    int x = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}
int func(int n) {

    vector <int> ar(2);
    vector <vector <int>> temp(2,vector <int>(2));
    vector <vector <int>>I(2,vector <int>(2,0));
    ar[0] = 0, ar[1] = 1;
    I[0][0] = I[1][1] = 1;
    temp[0][0] = 0;
    temp[0][1] = 1;
    temp[1][0] = 1;
    temp[1][1] = 1;

    while(n) {
      if(n&1) {
            multiply(I,temp);
            n--;
      }
      else {
            multiply(temp,temp);
            n /= 2;
      }
    }
    return (ar[0]*I[0][0])+(ar[1]*I[1][0]);
}
