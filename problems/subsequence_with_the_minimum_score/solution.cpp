// courtesy : https://leetcode.com/problems/subsequence-with-the-minimum-score/discuss/3174328/C%2B%2B-longest-prefix-and-longest-suffix

class Solution {
public:
    int minimumScore(string s, string t) {
		// longest prefix 
		// longest suffix
		// dp1 := longest prefix
		vector<int> dp1(s.size(), -1);
		int j = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(i > 0)
				dp1[i] = dp1[i-1];
			if(j < t.size() && s[i] == t[j]) {
				dp1[i] = j;
				j++;
			}
		}
		// dp2 := longest suffix
		vector<int> dp2(s.size(), t.size());
		int k = t.size() - 1;
		for(int i = s.size() - 1; i >= 0; i--) {
			if(i < s.size() - 1)
				dp2[i] = dp2[i + 1];
			if(k >= 0 && s[i] == t[k]) {
				dp2[i] = k;
				k--;
			}
		}
        int tsize = t.size(), ssize = s.size();
		int ans = min(tsize - (tsize - dp2[0]), tsize - dp1[ssize - 1] - 1);
		for(int i = 0; i < s.size() - 1; ++i) {
			int prefix = dp1[i] + 1;
			int suffix = tsize - dp2[i + 1];
			ans = min(ans, max(tsize - prefix - suffix, 0));
		}
		return ans;
    }
};