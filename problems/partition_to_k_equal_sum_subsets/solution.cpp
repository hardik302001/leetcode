// same as : https://leetcode.com/problems/matchsticks-to-square
// pseudo code same as : sudoku solver
// backtracking




class Solution {
public:
    int n;
    int visited[16];   // see contsraints
    
    bool possible(vector<int>& nums, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)  // bcz if one side is left , means (k-1) side full done , means we will surely make the 4th side
            return true;
        
        if(numsIndex>=n) //This line is important to avoid tle
           return false;
        
        if(currSum == subsetSum) {
            return possible(nums, 0, 0, subsetSum, k-1);  // start again, idx = 0, cur = 0, k-=1
        }
        
        for(int i = numsIndex; i<n; i++) {
            if(visited[i] || currSum + nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += nums[i];
            
            if(possible(nums, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        if(sum%k != 0)
            return false;
        
        memset(visited, 0, sizeof(visited));
        
        n                   = nums.size();
        int subsetSum       = sum/k;
        sort(begin(nums),end(nums),greater<int>());  // For avoid extra calculation
        
        return possible(nums, 0, 0, subsetSum, k);
    }
};