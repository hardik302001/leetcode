// brute force

class Solution {
public:
    bool matchReplacement(string s, string p, vector<vector<char>>& A) {
        map<char, set<char>> mp;
        for (auto& e : A) {
            mp[e[0]].insert(e[1]);
        }
        int n = s.size(), m = p.size();
        for (int i = 0; i + m <= n; ++i) {
            bool ok = true;
            for (int j = 0; j < m; ++j) {
                if (s[i+j] == p[j] || mp[p[j]].count(s[i+j])) continue;
                ok = false;
                break;
            }
            if (ok) return true;
        }
        return false;
    }
};