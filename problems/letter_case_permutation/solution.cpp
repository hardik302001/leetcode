class Solution {
public:
    
    vector<string>ans;
    
    
    void backtrack(string &s , string cur , int ind){
        if(cur.size()==s.size()){
            ans.push_back(cur);
            return;
        }
        if(isdigit(s[ind])){
            backtrack(s , cur + s[ind] , ind+1);
        }else{
            char lower = tolower(s[ind]);
            char upper = toupper(s[ind]);
            backtrack(s , cur + lower , ind+1);
            backtrack(s , cur + upper , ind+1);
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        string cur ;
        backtrack(s , cur , 0 );
        return ans;
    }
};