class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;  // bcz initially it is at nums[0]
        int n = nums.size();
        if(n==1) return true;
        for(int i = 0;i<n;i++){
            if(i>m) return false; 
            m = max( m , i+ nums[i]);
        }
        return true;
    }
};