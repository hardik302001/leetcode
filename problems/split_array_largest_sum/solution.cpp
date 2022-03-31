// exactly same as: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// do read below problem!
// same as : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// minimise maximum, 
/*
    # minimise maximum, so we return do hi = mid for valid case, and return low
    # if it was maximise minimum, then we will do li = mid +1 for valid case and return li - 1
    #                        OR
    # keep a speerate variable ans , and equate ans to the value, whenever we get valid result for answer from function
*/

// Given an array of nn integers and a value X, determine the minimum number of subarrays the array needs to be divided into such that no subarray sum is greater than X.

// minimise maximum
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
        return false;  // bcz we need count subarray to manintain maximum as mid, but we can only have atmost m subarrays, so we failed, so fuck off 
        
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

