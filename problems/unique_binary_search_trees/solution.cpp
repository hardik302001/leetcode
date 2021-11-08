//https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)

// TC : O(n^2) 
// SC : O(n)

/*

 * Taking 1~n as root respectively:
 *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
 *      2 as root: # of trees = F(1) * F(n-2) 
 *      3 as root: # of trees = F(2) * F(n-3)
 *      ...
 *      n-1 as root: # of trees = F(n-2) * F(1)
 *      n as root:   # of trees = F(n-1) * F(0)
 *
 * So, the formulation is:
 *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
 
*/



class Solution {
public:
    vector<int>dp = vector<int>(21,0);
    int numTrees(int n) {

        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; i++) {     //if we have i elements then, 
            
            for (int j=1; j<=i; j++) {        //we can have root from j = 1 to j = i, total cases will be summation for same
                dp[i] += dp[j-1] * dp[i-j];     //j-1 for left trre, i-j because now we have i elements, right subtree will have (i-j) cases
            }
        }
        return dp[n];
    }
};

