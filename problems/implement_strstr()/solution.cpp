// pi[i] = largest k(length) for pref(s[:i])== suf(s[:i]) such that s[i:k]==s[i-k+1:] 


class Solution {
public:
    
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    
    int strStr(string haystack, string needle) {
        vector<int> pi = prefix_function(needle + "#" + haystack);
        int n = haystack.size();
        int m = needle.size();
        int res = -1;
        
        for(int i = 0; i<(m+n+1);i++){
            if(pi[i]==m){
                res = i-2*m;    //visit https://cp-algorithms.com/string/prefix-function.html for more info
                break;
            }
        }
        
        return res;
    }
};