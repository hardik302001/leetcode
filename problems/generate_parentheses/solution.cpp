class Solution {
public:
    vector<string>ans;
    
    void solve(string cur, int open , int close, int n){
        if(open+close==2*n and open==close){
            ans.push_back(cur);
            return;
        }
        
        if(open>close or open==n){
            solve(cur + ')', open , close+1, n);
        }
        
        if(open<n){
            solve(cur + '(', open+1, close , n);            
        }


    }
    vector<string> generateParenthesis(int n) {
       string s;
        solve(s,0, 0 , n);
        return ans;
        
    }
};