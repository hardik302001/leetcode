// dp soln
/*
class Solution {
public:
    
    int maxSatisfaction(vector<int>& sat) {
        vector<vector<int>> dp(501 , vector<int>(501 , -1));
        sort(sat.begin(), sat.end());
        return recur(1 , 0 , sat , dp);
    }
    
    int recur(int x , int i , vector<int>&sat , vector<vector<int>> &dp){
        if(i>=(sat.size())){
            return 0;
        }
        if(dp[x][i]!=-1){
            return dp[x][i];
        }
        
        return (dp[x][i] = max(recur(x , i+1, sat , dp) , sat[i]*x + recur(x+1 , i+1 , sat , dp)));
    }
};

*/


// greedy
class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size(),sum=0;
        for(int i=n-1;i>0;i--)
            s[i-1]+=s[i];
        int i=0;
        while(i<n){
            if(s[i]>=0) sum+=s[i];
            i++;
        }
        return sum;
    }
};