// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// pdeuso code from LC SUDOKU SOLVER

class Solution {
public:
    int n;
    int visited[16];
    
    bool possible(vector<int>& matchsticks, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)  // bcz if one side is left , means 3 side full done , means we will surely make the 4th side
            return true;
        if(currSum == subsetSum) {
            return possible(matchsticks, 0, 0, subsetSum, k-1);  // idx = 0, cur = 0
        }
        
        if(numsIndex>=n) //This line is important to avoid tle
           return false;
        
        for(int i = numsIndex; i<n; i++) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += matchsticks[i];
            
            if(possible(matchsticks, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= matchsticks[i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        int k   = 4; //using concept of Leetcode Problem "Partition to K Equal Sum Subsets"
        /*
            If we are able to divide array in 4 parts each of which has equal sum (side of square)
            then it's possible to form the square with that equal subset sum as the side of square
        */
        
        if(sum%4 != 0)
            return false;
        
        
        memset(visited, 0, sizeof(visited));
        
        n                   = matchsticks.size();
        int subsetSum       = sum/4;
        sort(begin(matchsticks),end(matchsticks),greater<int>());  // For avoid extra calculation
        
        return possible(matchsticks, 0, 0, subsetSum, k);
    }
};