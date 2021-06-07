class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      vector<vector<int>>res(r,vector<int>(c));
          int n = mat.size();
          int m = mat[0].size();
          int rr = 0;int cc= 0;
          if ((n*m)!=(r*c)){
              return mat;
          }
          for(int i = 0;i<mat.size();i++){
              for(int j = 0;j<mat[0].size();j++){
                  int x = mat[i][j];
                  res[rr][cc] = x;
                  cc++;
                  if(cc==c){
                      cc = 0;
                      rr++;
                  }
              }
          }
        
        return res;
    }
};