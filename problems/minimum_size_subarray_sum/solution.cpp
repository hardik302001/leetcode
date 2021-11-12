class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int s = 0;
        int m  = INT_MAX;
        for(r = 0;r<n;r++){
            s = s+ nums[r];
            while(s>=target){
                m = min(m , r-l+1);
                s = s -  nums[l];
                l++;
            }
            
            
        }
        return m==INT_MAX?0:m;
    
    }
};