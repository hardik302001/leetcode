class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                st.push(s[i]);
            }
            else{
                char c = s[i];
                if(st.empty()) return false;
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        
        if(st.empty()){
            return true;
        }
        return false;
    }
};