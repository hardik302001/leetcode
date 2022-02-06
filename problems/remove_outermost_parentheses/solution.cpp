class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        int n = s.size();
        vector<int>ind;
        int c = 0;
        for(int i = 0;i<n;i++){
            if(st.empty() or s[i]=='('){
                st.push(i);
                c = c + 1;
            }
            else{
                if(s[st.top()]=='('){
                    c = c - 1;
                    if(c==0){
                        ind.push_back(st.top());
                        ind.push_back(i);
                    }
                    
                    st.pop();
                }
                else{
                    
                }
            }
        }
    
        
        string ans = "";
        int pos = 0;
        for(int i = 0;i<n;i++){
            if(pos<ind.size() and i==ind[pos]){
                pos++;
            }else{
                ans = ans + s[i];
            }
        }
        return ans;
    }
};