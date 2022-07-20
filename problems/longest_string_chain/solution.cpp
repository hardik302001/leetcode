// dp
// similar to lis - bottm up
/*
Time Complexity: O(nlog(n) + nll)
O(nlog(n)) for sorting
O(nll): n for each loop, l for inner loop and l for string concatenation.

Space Complexity: O(ns)
O(n) for both sorting and storing in dictionary.
O(ns): s for creating space for prev, n times.
*/

class Solution {
public:

    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), compare);   // reveerse sort on basis of length
        int res = 1;
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end() and dp[word]<dp[prev]+1) {
                    dp[word] = dp[prev] + 1;
                }
            }
            res = max(res, dp[word]);
        }
        return res;
    }
};