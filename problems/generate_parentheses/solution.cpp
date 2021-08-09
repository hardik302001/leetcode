class Solution {
public:
    vector<string>result;
    
    void solve(string output, int n, int open, int close, int i){
        
        //base case
        if(i==2*n){
            result.push_back(output);
            return;
        }
        
        //open
        if(open<n){
            solve(output+'(',n, open+1, close, i+1);
        }
        
        //close
        if(close<open){
            solve(output+')',n,open, close+1,i+1);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        string output = "";
        solve(output,n,0,0,0);    
        return result;
    }
};