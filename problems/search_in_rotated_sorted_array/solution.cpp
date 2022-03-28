class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r= n-1;
        
        while(l<r){
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
                return m;
            }
        }
        
        cout<<l<<endl;
        return nums[l]==target?l:-1;
    }
};