class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n-2;
        while(ind>=0 and nums[ind]>=nums[ind+1]){
            ind--;
        }
        if(ind==-1){
            reverse(nums.begin() , nums.end());
            return;
        }
        int swa = n-1;
        while(swa>ind and nums[swa]<=nums[ind]){
            swa--;
        }
        
        swap(nums[swa] , nums[ind]);
        reverse(nums.begin() + ind +1 ,nums.end());
        
    }
};