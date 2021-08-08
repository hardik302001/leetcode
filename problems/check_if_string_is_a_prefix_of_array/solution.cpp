class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string p;
        for(string t : words) {
            p += t;
            if(p == s) return 1;
        }
        return 0;
    }
};