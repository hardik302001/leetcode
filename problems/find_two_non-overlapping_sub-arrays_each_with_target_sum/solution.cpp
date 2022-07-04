class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n,INT_MAX); //dp[i] is the minimum length of subarray from 0 to i (inclusive) that has sum = target
        int l = 0, r = 0; //left and right pointers
        int len = INT_MAX; //current length of the window
        int currSum = 0; 
        int ans = INT_MAX; //answer to return
        while(r < n){
            currSum+= arr[r];
            while(currSum > target){ //if currentSum is greater than target, then start shrinking the window from left till sum <= target
                currSum -= arr[l];
                l++;
            }
            if(currSum == target){ //if we do get currSum equal to target, then our ans should be updated with minLen before left pointer and min length starting from left pointer
                if(l > 0 && dp[l-1]!= INT_MAX)
                    ans = min(ans, dp[l-1]+ r-l+1);
                len = min(len,r-l+1); //current answer for dp[r], i.e., min len of subarray with sum = target till r inclusive
            }
            dp[r] = len; //ultimately we are using the dp array only when we look back from a right pointer to a left pointer
            r++;
            
        }
        return ans == INT_MAX ? -1 : ans; 
    }
};




/*

A tip for someone else who may be struggling like I was on this line: 'ans = min(ans, dp[l-1]+ r-l+1);'

The reason we add dp[l-1] and 'r-l+1' is because dp[l-1] is the shortest subarray that is OUTSIDE the current window [l, r). Remember, the subarrays that constitute the solution cannot intersect. So we are adding up that subarray with the current subarray 'r-l+1'. Then, if that combo is shorter than 'ans', we update 'ans'.


*/