/*
    Approach : DP + HashSet
We can only buy a ticket on a day we fly, not on other days. So we need a quick way to check if given a day x, whether it exists in days. For this we can use a HashSet or std::unordered_set.
dp[i] = min cost for ticket on day i

    Complexity
Time: O(n)
Space: O(n)
where n is the last day.   

*/

class Solution {
public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            
            int n = days.back();
            vector<int> dp(n + 1, 0);
            unordered_set<int> seen(days.begin(), days.end());

            // dynamic programming
            for (int i = 1; i <= n; i++) {
                if (!seen.count(i))        //if it is not in days vector, we need not do anything
                    dp[i] = dp[i - 1];
                else
                    dp[i] = min({dp[max(0, i -  1)] + costs[0],  // all magic is done by dp[0], bcz dp[0]==0 we can extend  dp[i] to dp[i-1] , dp[i-7] , dp[i-30] dpeending upon situation...
                                 dp[max(0, i -  7)] + costs[1],
                                 dp[max(0, i - 30)] + costs[2]});
            }

            return dp[n];
        }


};