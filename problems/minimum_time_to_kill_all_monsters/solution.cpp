class Solution {
public:
     long long dp[18][1<<18] = {}, total = 0, n = 0;
    long long dfs(int gain, int mask, vector<int> &strength) {
        if (mask == total) return 0;
        if (!dp[gain][mask]) {
            dp[gain][mask] = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                int j = 1<<i;
                if (j&mask)
                    continue;
                long long wait = (strength[i]+gain-1)/gain ;
                dp[gain][mask] = min(dp[gain][mask], wait + dfs(gain+1, mask|j, strength));
            }
        }
        return dp[gain][mask];
    }
    long long minimumTime(vector<int>& strength) {
        n = strength.size(); total = (1<<n) - 1;
        return dfs(1, 0, strength);
    }
};