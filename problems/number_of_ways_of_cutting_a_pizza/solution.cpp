// courtesy : https://www.youtube.com/watch?v=4XxbmV6Ikz8

// also see : https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/discuss/623954/C%2B%2B-Solutions-w-Prefix-sum-%2B-DP-and-wo-Prefix-sum(Smart-pruning)-%2BDP 

static int MOD=1e9+7;
class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> prefixSum;
    int getApples(int row1,int col1,int row2,int col2)  //Get number of apples for the rectangle formed by the provided parameters
    {
        return prefixSum[row2+1][col2+1]-prefixSum[row1][col2+1]-prefixSum[row2+1][col1]+prefixSum[row1][col1];
    }
    int dp(vector<string>& pizza,int left,int top,int k)
    {
        if(memo[top][left][k]!=-1)
            return memo[top][left][k];
        if(k==1)
            return getApples(top,left,pizza.size()-1,pizza[0].size()-1)!=0;     //If this region has apples return 1 else 0
        memo[top][left][k]=0;
        for(int c=left;c<pizza[0].size()-1;c++)     //Move the left boundary till the last column (excluding the last column)
            if(getApples(top,left,pizza.size()-1,c))    //If apples exist in the left partition.
               memo[top][left][k]=(memo[top][left][k]+dp(pizza,c+1,top,k-1))%MOD;  
        for(int r=top;r<pizza.size()-1;r++)         //Move the top boundary till the last row (excluding the last row)
            if(getApples(top,left,r,pizza[0].size()-1)) //If apples exist in the top partition.
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,left,r+1,k-1))%MOD;
        return memo[top][left][k];
    }
    int ways(vector<string>& pizza, int k) 
    {
        memo.resize(pizza.size(),vector<vector<int>>(pizza[0].size(),vector<int>(k+1,-1)));
        prefixSum.resize(pizza.size()+1,vector<int>(pizza[0].size()+1,0));      //Prefix sum to get the number of apples in a region in O(1)
        for(int i=0;i<pizza.size();i++)
            for(int j=0;j<pizza[0].size();j++)
                prefixSum[i+1][j+1]=prefixSum[i+1][j]+prefixSum[i][j+1]-prefixSum[i][j]+(pizza[i][j]=='A');
        return dp(pizza,0,0,k);
    }
};

/*
Complexity
Time: O(k*m*n*(m+n))
Space: O(k*m*n).
*/