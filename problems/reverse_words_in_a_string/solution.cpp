class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = 0, n = s.size();
        while(i < n && s[i] == ' ') i++;   // eliminating preceding spaces
        
        while(i < n) {
            while(i < n && s[i] == ' ') i++;  // extra space elimination between words
            string tmp = "";
            while(i < n && s[i] != ' ') {
                tmp.push_back(s[i]);
                i++;
            }                                  //pushing in temp and reveersing temp to get exact word and add in res with space:    same as split in python
            reverse(tmp.begin(), tmp.end());
            res += tmp + " ";  // single space after each word
        }
        while(res.size() > 0 && res.back() == ' ') // eliminating extra leading spaces
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};