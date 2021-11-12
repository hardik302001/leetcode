//pref sum + map 
//O(n)
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/1353917/C%2B%2B-Binary-Search-to-Hash-Map


//also see prev code


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX, suffix_sum = 0, prefix_sum = 0;
        unordered_map<int, int> suffix;
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum += nums[i];
            if (suffix_sum == x)
                ans = min(n - i, ans);
            suffix[suffix_sum] = i;
        }
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            if (prefix_sum == x)
                ans = min(i + 1, ans);
            int target = x - prefix_sum;
            if (suffix.find(target) != suffix.end() && suffix[target] > i)
                ans = min(ans, i + 1 + n - suffix[target]);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};