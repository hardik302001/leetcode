class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i=0; i<nums.size(); i++){
            res ^= i;
            res^= nums[i];
        }
        return res;

    }
};

/*
 nums = [3,0,1]
 
 res = 3
 
 res = 3^ (3^0) ^ (0^1) ^ (1^2)
 res = 2
 


*/