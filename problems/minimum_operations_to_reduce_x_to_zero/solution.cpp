class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), j = 0, sum = 0, maxlen = -1;
        int total = accumulate(begin(nums), end(nums), 0);
        if(total < x) return -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > total - x)
                sum -= nums[j++];
            if(sum == total - x) 
                maxlen = max(maxlen, i - j + 1);
        }
        return maxlen == -1 ? -1 : n - maxlen;
    }
        
    
};