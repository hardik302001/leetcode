// exactly same as: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    
    bool helper(int mid,vector<int>& nums,int m){
        int count=1,sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                count++;
                sum=nums[i];
            }
        }
        if(count<=m)         // bcz m <= nums.length
            return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int maxCapacity=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            maxCapacity+=nums[i];
        
        int low=*max_element(nums.begin(),nums.end());
        int high=maxCapacity;
        
        while(low<high){
            int mid=low+(high-low)/2;
            if(helper(mid,nums, m)){
                high=mid;
            }
            else
                low=mid+1;
        }
        return low;
    
        
    }
};

