// exactly same as : https://leetcode.com/problems/search-in-rotated-sorted-array/
// just added some code for duplicates..

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r= n-1;
        
        while(l<r){
            
            // to avoid duplicates
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;
            
            
            int m = (l+r)/2;
            
            if(nums[m]>nums[r]){   // then first partitiion is monotonic and we will apply our search there!
                if(target>=nums[l] and target<=nums[m]){
                    r = m;
                }else{
                    l = m+1;
                }
            }else{          // then second partitiion is monotonic and we will apply our search there!
                if(target>=nums[m] and target<=nums[r]){
                    l = m+1;
                }else{
                    r = m;
                }
            }
            
            if(nums[m]==target){
                return true;
            }
        }
        
        return nums[l]==target?true:false;
    }
};