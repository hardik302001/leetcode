class Solution {
public:
    //move zero at end
    
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }

    //zeroat begin
    
    void moveZeroesatBEGIN(vector<int>& nums) {
        int n = nums.size();
        for (int lastNonZeroFoundAt = n-1, cur = n-1; cur >= 0; cur--) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt--], nums[cur]);
            }  
        }
    }
};