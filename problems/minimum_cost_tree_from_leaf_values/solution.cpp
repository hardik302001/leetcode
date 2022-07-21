// MCM DP Partition
// TC: O(n^3)

class Solution {
public:
    int soln(vector<int> a,int s,int e,vector<vector<int>> &dp)
    {
        if(s==e)    // for s==e, it is return 0, bcz it will be leaf node, and we only need to consider non leaf node
            return 0;   
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int ans=INT_MAX;
        
        for(int i=s;i<e;i++)
        {
            int one=soln(a,s,i,dp);
            int two=soln(a,i+1,e,dp);
            int tmp=one+two+(*max_element(a.begin()+s,a.begin()+i+1))*(*max_element(a.begin()+i+1,a.begin()+e+1));
            
            ans=min(ans,tmp);
        }
        
        return dp[s][e]=ans;
    }
        
    int mctFromLeafValues(vector<int>& arr)
    {
        vector<vector<int>> dp(50,vector<int>(50,-1));
        return soln(arr,0,arr.size()-1,dp);
    }
};