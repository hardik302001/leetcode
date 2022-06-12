// wrong answer with bfs , idk why??


// dp soln

class Solution {
public:
    // to track the forbidden positions
    unordered_map<int,int>m;
    int dp[7001][2];
    
    int solve(int i,bool back,int a,int b,int x)
    {
        // base case
        if(i == x)return 0;
        // you cannot land on -ve n0.and blocked positions
        if( i < 0 || m.find(i)!= m.end() || i>6000 )
            return 1e9;
        
        
        if(dp[i][back]!=-1)return dp[i][back];
        int forward = 0;
        // either go forward 
        dp[i][back] = 1 + solve(i+a,0,a,b,x);
        //go backward but cannot go consecutively 2 times
        if(!back)
        {
            dp[i][back] = min(dp[i][back],1 + solve(i-b,1,a,b,x));
        }
      
        return dp[i][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        for(int i = 0 ; i<forbidden.size();i++)
            m[forbidden[i]] = 1;
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,a,b,x);
        if(ans > 1e9)return -1;
        return ans;
    }
};