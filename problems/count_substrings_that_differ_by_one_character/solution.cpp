// courtesy : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/discuss/917690/C%2B%2B-O(N3)-with-explanation


// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s, string t) {
        int M = s.size(), N = t.size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) continue;
                int left = 1, right = 1;
                while (i - left >= 0 && j - left >= 0 && s[i - left] == t[j - left]) ++left;
                while (i + right < M && j + right < N && s[i + right] == t[j + right]) ++right;
                ans += left * right;
            }
        }
        return ans;
    }
};