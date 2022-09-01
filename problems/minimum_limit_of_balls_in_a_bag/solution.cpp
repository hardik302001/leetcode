class Solution {
public:
    
    bool check(vector<int>&nums, int m , int maxOperations){
        int c = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            c += ((nums[i]+m-1)/m)-1;
        }
        return c<=maxOperations;
        
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1 ;
        int r = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        if(maxOperations==1){
            return (nums[0]+1)/2;
        }
        
        int ans = nums[n-1];
        while(l<r){
            int m = l + (r-l)/2;
            if(check(nums, m, maxOperations)){
                ans = m;
                r = m;
            }else{
                l = m + 1;
            }
        }
        
        return ans;
        
    }
};