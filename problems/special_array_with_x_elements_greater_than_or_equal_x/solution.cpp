class Solution {
public:
    int solve(vector<int>& nums,int val){
        int count=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>=val){
                ++count;
            }
        }
        return count;
    }
    int specialArray(vector<int>& nums) {
       int low=0,high=1000;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int comp=solve(nums,mid);
            
            if(comp==mid){
                return comp;
            }
            if(comp>mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};