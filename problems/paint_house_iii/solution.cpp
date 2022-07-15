// very important dp ques, 
// courtesy : fraz -> https://www.youtube.com/watch?v=7Evjw2VM240&t=132s


#define BIG INT_MAX/2    // to avoid overflow,
class Solution {
public:
    
    int dp[101][21][101];
    
    int solve(int i , int last , int housecount , vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        
        if(housecount>target) return BIG;  // bcz here we have to minimise
        if(i==m){ // all houses traversed
            if(housecount==target){
                return 0;
            }else{
                return BIG;
            }
        } 
        
        if(dp[i][last][housecount]!=-1){
            return dp[i][last][housecount];
        }
        
        int ans = BIG;
        if(houses[i]==0){   // house shud be painted
            for(int j = 0;j<n;j++){  // see from all colors
                ans = min(ans , cost[i][j] + solve(i+1, j+1 ,(j+1==last)?housecount:housecount+1, houses , cost , m , n , target));
            }
        }else{              // house already painted, so compare with current color
            ans = min(ans , solve(i+1, houses[i] ,(houses[i]==last)?housecount:housecount+1, houses , cost , m , n , target));
        }    
        
        return dp[i][last][housecount] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp , -1 , sizeof dp);
        int res = solve(0 , 0 , 0 , houses , cost , m , n , target);
        return res==BIG?-1:res;
        
    }
};


// ----------------------------------------------------------------------------


/*

PAINT HOUSE 1:

Description
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.


TC : O(n*3*3)
// top down
class Solution {
public:
    int dp[3][100001];
    int solve(int col , vector<vector<int>>&costs , int n , int i){
        if(i==n){
            return 0;
        }
        if(dp[col][i]!=-1){
            return dp[col][i];
        }
        int currMin = INT_MAX ;
        for ( int colorIdx = 0; colorIdx < 3; colorIdx++ ){
            if (colorIdx != col){
                currMin = min(currMin, solve(colorIdx, costs , n, i+1));
            }
        }
        dp[col][i] =  (costs[i][col]  + currMin);
        return dp[col][i];
    }

    int minCost(vector<vector<int>> &costs) {
        int n  = costs.size();
        int ans = 1000000;
        int ind = 0;
        memset(dp , -1 , sizeof dp);
        for(int i = 0;i<3;i++){
            ans = min(ans , solve(i, costs , n, ind));
        }
        return ans;
    }
};


// bottom up
class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n= costs.size();
        if(n==0)
            return 0;
    
        for(int i=1; i<n; i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
    
        return min({costs[n-1][0], costs[n-1][1], costs[n-1][2]});
    }
};


*/


// ------------------------------------------------------------------------------------------



/*

PAINT HOUSE 2

Description
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

TC: O(n*k*k)
// top down
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

OPTIMISED VERSION
idea similar to : https://leetcode.com/problems/minimum-falling-path-sum-ii/

Currently this solution takes O(nk^2). Iterating all combinations takes O(nk). Finding the minimum among colors takes O(k). The optimization here is to reduce finding minimum to O(1). I do not need to find minimum for every color, because all I need is the minimum and the next minimum. If current color is the same as the previous color, which happens to have the minimum cost, I can just use the second minimum

TC: O(nk)
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

*/