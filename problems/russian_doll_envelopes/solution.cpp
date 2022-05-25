// lis
// O(n^2) dp
// TLE
/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if (envelopes.size()==0) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i]  = max(dp[i] , dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};
*/



// also implement it using nlogn lis
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        vector<int> dp;
        for (auto e : envelopes)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *iter)
                *iter = e[1];
        }
        return dp.size();
    }
};