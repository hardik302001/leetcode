class Solution {
public:
    set<string>ans;
    int mi = 1000000;
    void backtrack(int i, int open , int close , int minRem , string &cur ,  string &s){
        int n = s.size();
        if(i==n){
           
            if(open==close){
                if(minRem<mi){
                    ans.clear();
                    mi = minRem; 
                    ans.insert(cur);
                }else if(minRem==mi){
                    ans.insert(cur);
                }
            }
            
            return;
        }
        
        int o = 0, c = 0;
        if(s[i]=='('){
            o++;
        }else if(s[i]==')'){
            c++;
        }
        
        backtrack(i+1, open , close , minRem+1 , cur , s);
        if(open+o>=close+c){
            cur+=s[i];
            backtrack(i+1, open+o , close +c ,minRem , cur ,s );
            cur.pop_back();
        }  
        
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        string temp;
        backtrack(0 , 0 , 0 , 0, temp , s);
        vector<string>res;
        for(auto x: ans) res.push_back(x);
        return res;
    }
};