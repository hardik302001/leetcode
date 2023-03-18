
// TC: O(n*k*k)
// top down
/*
class Solution {
public:
    int dp[405][20005];
    int solve(int col , vector<vector<int>>&costs , int n , int i){
        int k = costs[0].size();
        if(i==n){
            return 0;
        }
        if(dp[col][i]!=-1){
            return dp[col][i];
        }


        int currMin = INT_MAX ;
        for ( int colorIdx = 0; colorIdx < k; colorIdx++ ){
            if (colorIdx != col){
                currMin = min(currMin, solve(colorIdx, costs , n, i+1));
            }
        }
        dp[col][i] =  (costs[i][col]  + currMin);
        return dp[col][i];
    }

    int minCostII(vector<vector<int>> &costs) {

        int n  = costs.size();
        if(n==0) return 0;
        int ans = INT_MAX;
        int ind = 0;
        int k = costs[0].size();
        cout<<n<<" "<<k<<endl;
        memset(dp , -1 , sizeof dp);
        for(int i = 0;i<k;i++){
            ans = min(ans , solve(i, costs , n, ind));
        }
        return ans;
    }
};
*/

// OPTIMISED VERSION
// idea similar to : https://leetcode.com/problems/minimum-falling-path-sum-ii/

/*
Currently this solution takes O(nk^2). Iterating all combinations takes O(nk). Finding the minimum among colors takes O(k). The optimization here is to reduce finding minimum to O(1). I do not need to find minimum for every color, because all I need is the minimum and the next minimum. If current color is the same as the previous color, which happens to have the minimum cost, I can just use the second minimum
*/

// TC: O(nk)
// for more info : http://buttercola.blogspot.com/2015/09/leetcode-paint-house-ii.html
class Solution {
public:
    int minCostII(vector<vector<int>> &mat) {

        int n  = mat.size();
        if(n==0) return 0;
        int ind = 0;
        int k = mat[0].size();
        
        vector<vector<int> > dp(n, vector<int>(k,0));
        for(int j = 0;j<k;j++){
            dp[n-1][j] = mat[n-1][j];     //last row, no variation
        }
        
        for(int i = n-2;i>=0;i--){
            int mini1 = INT_MAX, mini2 = INT_MAX;
            int ind = -1;      //index of mini1
            
            // find min of prev row
            for(int j = 0;j<k;j++){
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
            for(int j = 0;j<k;j++){
                if(ind==j){
                    dp[i][j] = mat[i][j] + mini2;  // go with mini2
                }
                else{
                    dp[i][j] = mat[i][j] + mini1;  // else with mini1
                }
            }
        }
        
      
        // res = minimum f first row
        int res = INT_MAX;
        for(int j = 0;j<k;j++){
            res = min(res, dp[0][j]);
        }
        return res;
    }
};
