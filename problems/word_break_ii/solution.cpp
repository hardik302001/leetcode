

// backtracking : O(n^n)
/*
class Solution {
public:
    vector<string> ans;
    unordered_set<string> hash;
    
    void helper(string s, vector<string> &curr){
        if(s.length() == 0){
            string res;
            for(int i=0;i<curr.size(); ++i){
                res += curr[i];
                if(i != curr.size() - 1) res+= " ";
            }
            ans.push_back(res);
            return;
        }
        
        for(int i=1;i<=s.length(); ++i){
            string left = s.substr(0, i);
            if(hash.count(left)) {
                curr.push_back(left);
                helper(s.substr(i), curr);
                curr.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> curr;
        for(auto x: wordDict) hash.insert(x);
        helper(s, curr);
        return ans;
    }
};
*/


// ------------------------------------------------------------------------------------------------------


// RECURSION + dp type
// memoising from s[:i] and finding s[i:n]
// if we get s[i:n] in dict, then we use our memoised result to get answer



class Solution {
public:
    unordered_map<string, vector<string>> m;           // used for memoisation
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {    
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict);
    }
    
    vector<string>solve(string s, unordered_set<string> dict){       // recursive function
        int n = s.size();
        if(m.count(s)) return m[s];    // take from memory
        vector<string> result;
        if(dict.count(s)){             // a whole string is a word
            result.push_back(s);
        }
        
        for(int i=1;i<s.size();++i){
            string word=s.substr(i, n);  
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,solve(rem,dict));     // recursion
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        
        m[s]=result; //memorize
        return result;
    }
    
    
    vector<string> combine(string word, vector<string> prev){        // string (s) = rem(s[0:i]) + word( substring s[i:n])
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
      
    
};


/*
Paraphrasing the solution in my words

lets take an example. s="catsand" and wordDict = ["cat", "cats", "and", "sand"].

The solution starts by taking the string S( "catsand") initially finding whether whole string is present or not . IN this case it is not present in the dict.

Now breaking the string and then finding
s.substr( i) gives the substring from ith index till the end. so string word goes as

atsand // not present
tsand // not present

sand //present then the remainder is calculated which is cat in this case and recursive function is called and same thing is done with cat which will return cat and also store the result in the unordered map . Now comes the combine part where both the string are combined and the pushed in the result " cat sand".

and // then comes and which is present so now again wordbreak called on remainder which is cats now and this will return cats. Now both strings are combined and inserted into result . result = {. "cat sand", "cats and"}; Now after the loop ending the result is returned and also stored in map.

Hope this helps.
*/

