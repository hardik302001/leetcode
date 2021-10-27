class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            return check1(s,x,y);    //look for "ba" first then "ab"
        }
        else{
            return check2(s,x,y);  //look for "ab" first then "ba"
        }
       
        
    }
    
    int check1(string s, int x, int y){
        int ans = 0;
        stack<int>st;
        int n =  s.size();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='a'){
                    if(st.top()=='b'){
                        ans = ans + y;
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        stack<int>st2;
        while(!st.empty()){
            char cur = st.top();
            st.pop();
            
            if(st2.empty()){
                st2.push(cur);
            }
            else{
                if(cur=='a'){
                    if(st2.top()=='b'){
                        ans = ans + x;
                        st2.pop();
                    }
                    else{
                        st2.push(cur);
                    }
                }
                else{
                    st2.push(cur);
                }
            }
        }
        
        return ans;
    }
    
    int check2(string s, int x, int y){
        int ans = 0;
        stack<int>st;
        int n =  s.size();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='b'){
                    if(st.top()=='a'){
                        ans = ans + x;
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        stack<int>st2;
        while(!st.empty()){
            char cur = st.top();
            st.pop();
            
            if(st2.empty()){
                st2.push(cur);
            }
            else{
                if(cur=='b'){
                    if(st2.top()=='a'){
                        ans = ans + y;
                        st2.pop();
                    }
                    else{
                        st2.push(cur);
                    }
                }
                else{
                    st2.push(cur);
                }
            }
        }
        
        return ans;
    }
    
};