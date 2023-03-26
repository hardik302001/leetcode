// total - odd

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long even_subs = nums.size() * (nums.size() + 1) / 2, odd_cnt = 0;
        for (auto n : nums) {
            odd_cnt = n % 2 ? odd_cnt + 1 : 0;
            even_subs -= odd_cnt;
        }
        return even_subs;
    }
};