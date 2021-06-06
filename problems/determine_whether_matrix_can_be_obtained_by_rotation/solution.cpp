class Solution {
public:
void sc(vector<vector<int> >& mat)
{
 
    // Traverse each cycle
    int N = mat.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = temp;
        }
    }
}
 
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        int N = mat.size();
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;

    }
    
 void sac(vector<vector<int> >& mat)
{
 
    // Traverse each cycle
    int n = mat.size();   
    
    
      for(int i=0;i<n/2;i++)
  {
      for(int j=i;j<n-i-1;j++)
      {
        // Swapping elements after each iteration in Anticlockwise direction
          int temp=mat[i][j];
          mat[i][j]=mat[j][n-i-1];
          mat[j][n-i-1]=mat[n-i-1][n-j-1];
          mat[n-i-1][n-j-1]=mat[n-j-1][i];
          mat[n-j-1][i]=temp;
      }
  }

 }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int i = 0;i<4;i++){
            sc(mat);
            bool ans = check(mat,target);
            if(ans){
                return true;
            }
        }
        
        
        for(int i = 0;i<4;i++){
            sac(mat);
            bool ans = check(mat,target);
            if(ans){
                return true;
            }
        }
        
        
        return false;
    }
};