// tc : O(n^2)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mi = nums[i];
            int ma = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                mi = min(mi, nums[j]);
                ma = max(ma, nums[j]);
                result += ma - mi;
            }
        }
        return result;
    }
};