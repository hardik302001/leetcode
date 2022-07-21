// good code

/*
m = len(cuts)
using memoization time complexity becomes O(m^2)*O(m) because we have 2 changing parameters here ie cut_start and cut_end (which actually contribute to time complexity, start and end are just for computing the length and a for loop which visits all the possible values which contribute to another O(m).
*/

class Solution {
public:
    int dp[101][101];
    
    int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end)
    {
        if(cuts_start>cuts_end)
            return 0;
        
        if(dp[cuts_start][cuts_end]!=-1)
            return dp[cuts_start][cuts_end];
        
        int minimum = INT_MAX;
        for(int i=cuts_start; i<=cuts_end; i++)
            minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1)+mincost(cuts[i], end, cuts, i+1, cuts_end));  // bcz cuts is sorted, we can directly send index as parameter, and we cant use 
        
        return dp[cuts_start][cuts_end] = minimum;
    }
    
    int minCost(int n, vector<int>& cuts) {

        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return mincost(0, n, cuts, 0, cuts.size()-1);
    }
};






//-----------------------------------------------------------------


// good ques

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/781068/Recursion-%2B-Memoization-or-Turned-into-Simple-DP-question-or-C%2B%2B

/*
class Solution {
public:
    int dp[102][102];
    
    int solve(vector<int> &cuts, int low, int high) {
        if(low+1==high) return 0;
        else if(dp[low][high]!=-1)
            return dp[low][high];
        
        else {
            int ans = INT_MAX;
            for(int i=low+1; i<high; i++) {  // bcz low can be 0
                int curr = cuts[high]-cuts[low] + solve(cuts, low, i) + solve(cuts, i, high);
                ans = min(ans, curr);
            }
            return dp[low][high] = ans;
        }
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size()-1);
    }
};
*/