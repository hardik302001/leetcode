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
    
    
    int repeatedStringMatch(string a, string b) {
        // min number of times we need to repeat the string
        // the size of a should be >= size of b
        const int min_repeat = ceil((float)b.size() / a.size());
        string temp;
        for(int i = 0; i < min_repeat; i++)
            temp += a;
        // substring is found
        vector<int>pi = prefix_function(b+ "#" + temp);
        for(int i = 0;i<(temp.size() + 1 + b.size());i++){
            if(pi[i]==b.size()){
                return min_repeat;
            }
        }
            
        // repeat a one more time
        temp += a;
        vector<int>pii = prefix_function(b+ "#" + temp);
        for(int i = 0;i<(temp.size() + 1 + b.size());i++){
            if(pii[i]==b.size()){
                return min_repeat+1;
            }
        }
  
        // b can never be a substring of a
        return -1;
    }
};