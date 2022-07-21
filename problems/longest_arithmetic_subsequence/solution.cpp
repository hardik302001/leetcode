
// leetcode 446, 413



// similar to LIS
/*

The main idea is to maintain a map of differences seen at each index.

We iteratively build the map for a new index i, by considering all elements to the left one-by-one.
For each pair of indices (i,j) and difference d = A[i]-A[j] considered, we check if there was an existing chain at the index j with difference d already.

If yes, we can then extend the existing chain length by 1.
Else, if not, then we can start a new chain of length 2 with this new difference d and (A[j], A[i]) as its elements.
At the end, we can then return the maximum chain length that we have seen so far.

dp[index][diff] equals to the length of arithmetic sequence at index with difference diff.


Complexity
Time O(N^2)
Space O(N^2)
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if (A.size() == 2) {
            return 2;
        }
        int len = A.size();
        int result = 0;
        vector<vector<int>> dp(A.size(), vector<int>(1001,1));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i]-A[j] + 500;  // bcz what if diff is < 0, 500 bcz see constraints
                dp[i][diff] = max(dp[j][diff] + 1 , 2);  // 2 bcz it will pair with j , if no prev chain with differnce = diff exists, else we use that chain 
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};
