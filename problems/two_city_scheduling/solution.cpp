
// also see py soln
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            int temp=costs[i][0]-costs[i][1];
            v.push_back({temp,i});
        }
        
        // sorted on the basis of costs[i][0] (left)
        sort(v.begin(),v.end());
        
        int res=0;
        int left=n/2;
        int right = n/2;
        
        // thats why choosing initial left elements from beginnibg
        for(int i=0;i<left;i++)
        {
            auto it=v[i];
            int ind=v[i].second;
            res+=costs[ind][0];
        }  
        
        // choosing right elements from end
        for(int i=n-1;i>=right;i--)
        {
            auto it=v[i];
            int ind=v[i].second;
            res+=costs[ind][1];

        }
        
        return res;
        
    }
};

//----------------------------------------------------------

// 2d dp
// first city, second city

/*
class Solution {
public:
    
    vector<vector<int>> dp;
    
    
    int recur(int fi , int se , vector<vector<int>>&costs){
        int n = costs.size();
        int i = fi + se -1;
        if(fi==0 and se==0) return 0;
        if(dp[fi][se]!=-1) return dp[fi][se];
        
        int mi = 1000000000;
        if(fi) mi = min(mi , costs[i][0] + recur(fi-1, se, costs));
        if(se) mi = min(mi , costs[i][1] + recur(fi, se-1, costs));

        return dp[fi][se] = mi;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        dp = vector<vector<int>>(51,vector<int>(51,-1));
        int n = costs.size();
        return recur(n/2, n/2, costs);
    }
};

*/



// -----------------------------------------------------------------
// 3d dp
// i , fi , se

/*
class Solution {
public:
    
    int dp[101][101][101];
    
    int recur(int i , int fi , int se , vector<vector<int>>&costs){
        int n = costs.size();
        if(i==n) return 0;
        if(dp[i][fi][se]!=-1) return dp[i][fi][se];
        
        int mi = 1000000000;
        if(fi) mi = min(mi , costs[i][0] + recur(i+1, fi-1, se, costs));
        if(se) mi = min(mi , costs[i][1] + recur(i+1, fi , se-1 , costs));
        
        
        return dp[i][fi][se] = mi;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp , -1 , sizeof dp);
        int n = costs.size();
        return recur(0, n/2, n/2, costs);
    }
};

*/