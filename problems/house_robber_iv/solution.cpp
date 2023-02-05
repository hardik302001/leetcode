// binary search + dp


class Solution {
public:
    
    bool check(int m , vector<int>&nums, int k)
    {
        int i=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]<=m) k--, i+=2;
            else i++;
        }
        return (k <= 0);
    }
    
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 1000000005;
        int ans = r;
        while(l<r){
            int m = (l+r)/2;
            if(check(m, nums , k)){
                ans = m;
                r = m;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};


/*
// other way to ckeck , using top dowm dp

    int recur(int i, vector<int>&nums , int m , vector<int>&dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = 0;
        int ignore = recur(i+1, nums , m , dp);
        if(nums[i]<=m) take = recur(i+2, nums , m , dp)+1 ;
        return dp[i]=max(ignore, take);
    
    }
    
    
    bool check(int m , vector<int>&nums, int k){  // how many element i can have , if i have minimum capability as m
        int n = nums.size();
        vector<int>dp(n, -1);
        int count = recur(0, nums , m  , dp);
        return count>=k;
    }

*/