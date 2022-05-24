

// backtracking

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //insert all the words in the set
        unordered_set<string> set;
        vector<string> res;
        for(auto word:wordDict)
            set.insert(word);
        //to store the current string 
        string curr="";
        findHelper(0,s,curr,set,res);
        return res;
    }
    
    void findHelper(int ind,string s,string curr,unordered_set<string> set,vector<string>& res)
    {
        if(ind==s.length())
        {
            //we have reached end
            curr.pop_back(); //remove the trailing space
            res.push_back(curr);
        }
        string str="";
        for(int i=ind;i<s.length();i++)
        {
            //get every substring and check if it exists in set
            str.push_back(s[i]);
            if(set.count(str))
            {
                //we have got a word in dict 
                //explore more and get other substrings
                findHelper(i+1,s,curr+str+" ",set,res);
            }
        }
    }
};



// ------------------------------------------------------------------------------------------------------

// RECURSION + dp type
/*
class Solution {
public:
    unordered_map<string, vector<string>> m;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {    
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict);
    }
    
    vector<string>solve(string s, unordered_set<string> dict){       //recursive function
        int n = s.size();
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i, n);  
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,solve(rem,dict));     //recursion
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

*/
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

