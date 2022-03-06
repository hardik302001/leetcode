class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        int n= s.length();
        for(int i=1;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
       
        reverse(res.begin(), res.end());
        return res;
    }
};