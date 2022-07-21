// O(nlogn) : LIS idea

class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>nums, int n){
       
        vector<int > v;
        vector<int>lis;
        lis.push_back(1);
        v.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
                lis.push_back(v.size());
            }
            else{
                int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[idx]=nums[i];
                lis.push_back(idx+1);
            }
        }
        
        return lis;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        // maximum length of bitonic subsequence
        
        int n = nums.size();
        vector<int> lis = longestIncreasingSubsequence(nums, n);
        
     
        reverse(nums.begin(), nums.end());
        vector<int> lds = longestIncreasingSubsequence(nums, n);
        reverse(lds.begin(), lds.end());

        int result=0;
        
        for(int i =0;i<nums.size();i++){
            if(lis[i]==1 || lds[i]==1) continue;   //ignore all those who is 1 because it doesnt not have any to it's left or right side
			
            result=max(result,lis[i]+lds[i]-1);  //subtracting 1 to prevent double counting
        }
        return nums.size()-result;
    }
};


//-------------------------------------------------------------------

// idea :  lis
// TC: O(n^2)

/*
class Solution {
public:
    //since we are using LIS the time complexity is O(n2).
     vector<int> LISlefttoright(vector<int>&nums){
        vector<int>dp(nums.size(),1);
        for(int i =1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                    
            }
        }
        return dp;
    
    }
    vector<int> LISrighttoleft(vector<int>&nums){
       
        vector<int>dp(nums.size(),1);
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
       vector<int>dp1=LISlefttoright(nums);
        vector<int>dp2=LISrighttoleft(nums);
        int result=-1;
        for(int i =0;i<nums.size();i++){
          
            if(dp1[i]==1 || dp2[i]==1) continue; 
            //see dp1 says that longest increasing subseq from left to that element
            // and if the value is 1 that simply means there are no elements to its left
            //the same way with dp2 which says about the longest increasing subseq from right to left
            // and if the value is 1 that simply means there are no elements to its right 
            // the value is 1 coz we are counting that particular element as well 
            result=max(result,dp1[i]+dp2[i]-1);  //subtracting 1 to prevent double counting
        }
        return nums.size()-result;
    }
};

*/