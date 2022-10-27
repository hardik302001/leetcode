// idea : https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/2734766/C%2B%2B-oror-prefix-sum-oror-Precomputation-oror-Detailed-Explanation 


class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < nums.size(); i++)
            v[i] = {nums[i], cost[i]};
        
        sort(v.begin(), v.end());
        vector<long long> pref(n), suff(n);
        // c_sum = summation (ci)
        // nc = summation (ai*ci)
        
        long long c_sum = 0, nc = 0;
        
        for(int i = 0; i < n; i++){
            pref[i] = (v[i].first * c_sum - nc);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        
        c_sum = 0, nc = 0;
        for(int i = n - 1; i >= 0; i--){
            suff[i] = (nc - v[i].first * c_sum);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        
        
        for(int i = 0;i<n;i++){
            ans = min(ans, suff[i] + pref[i]);
        }
        
        return ans;
    }
};