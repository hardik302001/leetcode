// we need not find minium for every elemenet in row, for each row, we will only find the first two min elements, and can use them alternately while considering the min path sum ..

// secondly, we must need path sum, irrespective of the way, so we could have gone from top to bottom , but in this codde we went from botoom to top, filling the dp array.. 
// dp[curi][curj] = prev dp[alpha][beta] + curr_element



// very similar idea to : paint house 2 and paint house 3

// tc: O(n*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n,0));
        for(int j = 0;j<n;j++){
            dp[m-1][j] = mat[m-1][j];     //last row, no variation
        }
        
        for(int i = m-2;i>=0;i--){
            int mini1 = INT_MAX, mini2 = INT_MAX;
            int ind = -1;      //index of mini1
            
            // find min of prev row
            for(int j = 0;j<n;j++){
               if(dp[i+1][j]<=mini1){
                   mini2 = mini1;
                   mini1 = dp[i+1][j];
                   ind = j;
               }
                else if(dp[i+1][j]<mini2){
                    mini2 = dp[i+1][j];
                }            
            }
            
            //now prev dp min + cur cell
            for(int j = 0;j<n;j++){
                if(ind==j){
                    dp[i][j] = mat[i][j] + mini2;  // go with mini2
                }
                else{
                    dp[i][j] = mat[i][j] + mini1;  // else with mini1
                }
            }
        }
        
      
        // res = minimum of first row
        int res = INT_MAX;
        for(int j = 0;j<n;j++){
            res = min(res, dp[0][j]);
        }
        return res;
    }
};