class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n + 1, 0);
        dp[1] = 1;
        int share = 0, mod = 1e9 + 7;
        int res = 0 ;
        for (int i = 2; i <= n; ++i){
            share = ((share%mod) +  (dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod)%mod;
            dp[i] = share;
        }
        
        for (int i = n - forget + 1; i <= n; ++i)
            res = (res + dp[i]) % mod;
        return res;
    }
};


/*
Explanation
dp[i] means the number of people who found the secret on ith day.
share is the number of people who are going to share the secrets.
On the ith day,
dp[i - delay] people found the secret delay days before,
starting to share the secret.
so share += dp[i - delay]

dp[i - forget] people found the secret forget days before,
and forgot the secret today.
so share -= dp[i - forget]
and we assign dp[i] = share.


Complexity
Time O(n)
Space O(n)
*/