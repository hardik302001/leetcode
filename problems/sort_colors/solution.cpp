class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int zero = 0;
        while(l<=r){
            if(nums[l]==0){
                swap(nums[l], nums[zero]);
                zero++;
                l++;   // if we get 0 ,  then endless loop
            }else if (nums[l]==1){
                l++;
            }else{
                swap(nums[l], nums[r]);
                r--;
            }
            
            
        }
    }
};