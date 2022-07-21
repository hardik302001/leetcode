// also see : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

/*
focus on the definition of dp[i] in your code..
according to your code , dp[i] = length of LIS that ends at index i,
rather not length of LIS uptil index i.

Thats why we take maximum for all dp[i], so that we can find LIS ending at all indexes, and choose maximum out of it.

*/

// O(n2) - > AC
// bottom up


// printing lis, keep track of indexes
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        int lastidx = 0;
        int ans = 0;
        vector<int>dp(n+1, 1), hash(n+1, -1);
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j] and dp[i]<1+dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(ans<dp[i]){
                ans = max(ans, dp[i]);
                lastidx  = i;                
            }

        }
        
        vector<int>lis;
        while(hash[lastidx]!=lastidx){
            lis.push_back(nums[lastidx]);
            lastidx =  hash[lastidx];
        }
        
        lis.push_back(nums[lastidx]);
        
        reverse(lis.begin(), lis.end());
        return ans;        
        
    }	
};

*/



// ------------------------------------------------------------------------------

// O(n2) - > TLE
// top down

/*
class Solution {
public:
    int solve(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
        if( ind == nums.size()) return 0;
        
        if( dp[ind][prev+1] != -1) return dp[ind][prev+1]; 
        if( prev ==-1 || nums[ind]> nums[prev]){
            return dp[ind][prev+1]= max( 1+ solve(nums,ind+1, ind, dp), solve( nums, ind+1, prev, dp));
        }
        
        else{
            return dp[ind][prev+1]=  solve(nums, ind+1, prev, dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
        return solve( nums, 0, -1, dp);
    }	
};

*/




// ----------------------------------------------------


// O(nlogn)
// striver bhai ne accha smjhaya h babes!
// https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44

// use lower_bound = gives arr[i]  pos , if exists, else first index greater than arr[i] 

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i = 1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }else{
                int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin(); // idx will always be less than / = to current temp size
                temp[idx] = arr[i];
                
                
            }
        }
    
        return temp.size();
    }
};