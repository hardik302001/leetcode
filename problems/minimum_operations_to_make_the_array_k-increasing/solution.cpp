// see https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// for more info




//  https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/discuss/1634980/C%2B%2B-Longest-Increasing-Subsequence

// Time: O(Nlog(N/k))
// Space: O(N/k)
// class Solution {
// public:
//     int kIncreasing(vector<int>& A, int k) {
//         int N = A.size(), ans = 0;
//         for (int i = 0; i < k; ++i) {
//             vector<int> v{A[i]};
//             int len = 1;
//             for (int j = i + k; j < N; j += k) {
//                 auto i = upper_bound(begin(v), end(v), A[j]);
//                 if (i == end(v)) v.push_back(A[j]);
//                 else *i = A[j];
//                 ++len;
//             }
//             ans += len - v.size();
//         }
//         return ans;
//     }
// };

// upper_bound solution
class Solution {
public:
    int LIS(vector<int> &arr) {
        vector<int> lis(arr.size(), INT_MAX);
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            int idx = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            ans = max(idx + 1, ans);
            lis[idx] = arr[i];
        }
        return arr.size() - ans;
    }
    int kIncreasing(vector<int>& arr, int k) {
        vector<vector<int> > group(k);
        for(int i = 0; i < k; i++) {
            for(int j = i; j < arr.size(); j+=k) {
                group[i].push_back(arr[j]);
            }
        }
        int ans = 0;
        for(auto &v : group) {
            ans += LIS(v);
        }
        return ans;
    }
};