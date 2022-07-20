/*

Time: O(N + S), where N <= 5*10^4 is length of string s, S <= 5000*50 is sum length of all words
Space: O(M), where M <= 5000 is size of words.

*/


// idea: https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation      
// see at the end of editorial

// idea: https://leetcode.com/problems/number-of-matching-subsequences/discuss/1290406/C%2B%2BJavaPython-Next-Letter-Pointers-Picture-explain-O(N-%2B-S)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<char , vector<string>>m;
        for(auto word: words){
            m[word.back()].push_back(word);
        }
        
        int c= 0;
        for(int i = s.size()-1;i>=0 ;i--){
            vector<string>word = m[s[i]];
            m[s[i]] = {};  //reset
            
            for(auto x: word){
                if(x.back()==s[i]){
                    if(x.size()==1){
                        c++;
                    }else{
                        x.pop_back();
                        m[x.back()].push_back(x);
                    }
                }
            }
        }
        return c;
        
    }
};