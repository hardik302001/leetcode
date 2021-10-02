//  https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/discuss/1499365/C%2B%2B-Frequency-Map-O(N)
// i still have some doubts,......maybe....watch yt


// OJ: https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int waysToPartition(vector<int>& A, int k) {
        long sum = accumulate(begin(A), end(A), 0L), N = A.size(), ans = 0;
        unordered_map<long, int> L, R;
        for (long i = 0, left = 0; i < N - 1; ++i) {
            left += A[i];
            long right = sum - left;
            R[right - left]++;
        }
        ans = R[0];
        for (long i = 0, left = 0; i < N; ++i) {
            left += A[i];
            long right = sum - left, d = k - A[i];
            ans = max(ans, (long)L[-d] + R[d]);
            R[right - left]--;
            L[right - left]++;
        }
        return ans;
    }
};