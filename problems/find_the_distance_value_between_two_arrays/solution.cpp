// For each A[i], find the length of range [A[i] - d, A[i] + d] in array B. If the length is 0, then increment the answer.

// The start point of the range (A[i] - d) can be found using lower_bound(begin(B), end(B), A[i] - d).

// The next element after the end point of the range (the element after A[i] + d) can be found using upper_bound(begin(B), end(B), n + d).

// If these two iterators are the same, it means the length of the range is 0.

// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        sort(begin(B), end(B));
        int ans = 0;
        for (int n : A) {
            if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) ++ans;
        }
        return ans;
    }
};