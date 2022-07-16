// see previous accepted code alos, that is based on rrecursion
// this code is based on dp!
// see aditya verma dp notes for more info

/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //basically target is difference of subsets
        //so we need to ocunt no of possible subsetwith given difference..
        
       
//         S1 - S2 = target
//         S1 + S2  = sum(nums)
//         so S1 = [ target + sum(nums) ]//2
        
        
        //now we need to find no of subsets with given sum S1..

        
        int sum = accumulate(nums.begin(),nums.end(),0);
        int s1 = (target + sum)/2;
        
        
        //s1 should not in fraction it shud be integer.
        
        if((target + sum)%2!=0){
            return 0;
        }
        
        
        //secondly s1 should be positive bcz we are considering array of size s1 for bottom up method, what if s1<0.
        
        if(s1<0){
            s1 = abs(s1);
        }
        
        
        int m = nums.size()+1;
        int n = s1+1;
        vector<vector<int> >dp(m, vector<int>(n,-1));
        
        for(int j = 0;j<n;j++){
            dp[0][j] = 0;
        }
        for(int i = 0;i<m;i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){             //j should begin wih zero
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            
            }
        }
        
        return dp[m-1][n-1];
        
    }
};

*/


/*
class Solution {
public:
    
    int dp[21][2001];
    int findTargetSumWays(vector<int>& nums, int target) {
        //basically target is difference of subsets

        int sum = accumulate(nums.begin(),nums.end(),0);
        int s1 = (sum+ target)/2;
        
        
        //s1 should not in fraction it shud be integer.
        
        if((target + sum)%2!=0){
            return 0;
        }


        int n = nums.size();
        memset(dp , - 1, sizeof dp);
        return recur(0 , 0 , nums , n ,  s1);
    }
    
     
    int recur(int idx ,  int cur , vector<int>&nums, int n, int sum)
    {
        if(idx>n) return 0;
        if(cur>sum) return 0;
        if(idx==n) return (cur==sum)? 1 :0;
        if(dp[idx][cur]!=-1) return dp[idx][cur];
        int ans =  recur(idx+1, cur , nums , n , sum) + recur(idx+1 , cur + nums[idx] , nums, n,  sum);
        
        return dp[idx][cur] = ans;
    }
    
    
};

*/

// tc: O(n*s)

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,int>> mem(nums.size());
        return find(0,nums,S,mem);    
    }
    int find(int p, vector<int>& nums, int sum, vector<unordered_map<int,int>>& mem) {
        if(p==nums.size()) return sum==0;
        auto it = mem[p].find(sum);
        if(it != mem[p].end()) return it->second;
        return mem[p][sum]=find(p+1,nums,sum+nums[p],mem)+find(p+1,nums,sum-nums[p],mem);
    }
};