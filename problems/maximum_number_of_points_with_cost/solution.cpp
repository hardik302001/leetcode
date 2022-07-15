// https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344908/C%2B%2BJavaPython-3-DP-Explanation-with-pictures.

// https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344888/C%2B%2B-dp-from-O(m-*-n-*-n)-to-O(m-*-n)

/*
To further reduce the time complexity, I found that there is some similar calculation when we are trying to find the max. That is dp[i - 1][k] - k (or + k depends on the position). To reduce to the smaller problem, we assume that all the max value is from the left side of the current position. With this assumption, the abs(k - j) can be changed to j - k. Due to other values (e.g. points[i][j]) are fixed. The problem becomes to find the max dp[i - 1][k] + k in the left. That is

dp[i][j] = max(dp[i - 1][k] + k) + points[i][j] - j for all 0 <= k <= j
You may notice that some of the sign is reversed, that is because of we need to subtract the cost.

Now, the right side is similar. If we assume max value is from the right side. The relation will be:

dp[i][j] = max(dp[i - 1][k] - k) + points[i][j] + j for all j <= k <= points[i].size() - 1
*/

// Time Complexity: O(n*m)
// Space Complexity: O(m)


#define ll long long

class Solution {
public:
    long long maxPoints(vector<vector<int>>& P) {
      ll n = P.size(), m = P[0].size();

      vector<ll> prev(m);   // dp array
      for(int i=0; i<m; ++i) prev[i] = P[0][i];
      
      for(int i = 1; i < n; ++i){
        vector<ll> curr(m, 0);
        auto right = curr, left = curr;
        
        
        // left[j] =  max( dp[current row - 1][j] + abs(j) for i in range(0 to j included)) 
        
        // traverse left to right
        left[0] = prev[0];
        for(int j=1; j<m; ++j) {
          left[j] = max(left[j-1]-1, prev[j]);    
        }
        
        
        // right[j] =  max( dp[current row - 1][j] + abs(j-i) for i in range(j included to m)) 
        // traverse right to left
        right[m-1] = prev[m-1];
        for(int j=m-2; j>=0; --j) {
          right[j] = max(right[j+1]-1, prev[j]);
        }
        
        // update current with max from left, right + value
        for(int j=0; j<m; ++j){
          curr[j] = P[i][j] + max(left[j], right[j]);       //P[i][j] is fixed so we added it at end
        }
        
        prev = curr;
      }
      
      ll ans = prev[0];
      for(auto &i: prev) ans = max(ans, i);
      return ans;
    }
};





//TLE: O(m*n*n) , bcz m*n for grid and n for traversing whole row again to find abs diff of all cases
// leetcode 931 and leetcode 1014
/*
class Solution {
public:
    
    int solve(int i,int j,int m,int n,vector<vector<int>>& p,
             vector<vector<int>> &dp)
    {
        if(j<0 or j>=n) return INT_MIN;
        if(i == m-1) return p[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int temp = INT_MIN;
        for(int x = 0;x< n;x++){
            int res = p[i][j] + solve(i+1,x,m,n,p,dp)- abs(j - x);
            temp = max(temp ,  res);
        }
        return  (dp[i][j] =  temp);
                
    }

    long long maxPoints(vector<vector<int>>& p) {
        int m = p.size();    
        int n = p[0].size();
        int ans = INT_MIN;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
           ans = max(ans,solve(0,j,m,n,p,dp));    
        }
        return ans;
    }
};

*/