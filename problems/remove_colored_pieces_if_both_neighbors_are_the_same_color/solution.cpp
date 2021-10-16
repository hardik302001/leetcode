class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        map<char, int> mp;
        for(int i = 1; i < n - 1; ++i) {
            if( s[i - 1] == s[i] and s[i] == s[i + 1]) {
                mp[s[i]]++;
            }
        }
        return ( mp['A'] > mp['B']);
    }
};