class Solution {
public:
        vector<int> getMaximumXor(const vector<int>& nums, const int maximumBit) const {
        
        vector<int> xors; xors.reserve(nums.size());
        xors.push_back(nums.front());
        for (int n = 1; n < nums.size(); ++n) {
            
            xors.push_back(xors[n - 1] ^ nums[n]);            
            
        }
        vector<int> res; res.reserve(nums.size());
        const int maxi = (1 << maximumBit) - 1;
        for (int n = 0; n < nums.size(); ++n) {
            res.push_back(maxi ^ xors[n]);
        }
            
        reverse(begin(res), end(res));
        return res;
    }
};