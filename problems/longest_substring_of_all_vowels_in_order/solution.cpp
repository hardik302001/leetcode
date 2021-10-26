// SLIDING WINDOW BASED STACK SOLN!
// see py pure sliding window soln!
//too good


class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if(word.size()<5)return 0;
        stack<char> st;
        int i=0,j=0,count=0,ans=0;
        while(i<word.size()){
            if(st.empty()&&word[i]!='a')i++;//checks if the first letter of the substring is 'a'
            else if(word[i]=='a'){
                if(st.empty()||st.top()=='a'){
                    st.push(word[i]);
                    count++;
                    i++;
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
            }
            else if(word[i]=='e'){
                if(st.top()=='a'||st.top()=='e'){
                    st.push(word[i]);
                    count++;
                    i++;
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
            }
            else if(word[i]=='i'){
                if(st.top()=='e'||st.top()=='i'){
                    st.push(word[i]);
                    count++;
                    i++;
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
            }
            else if(word[i]=='o'){
                if(st.top()=='i'||st.top()=='o'){
                    st.push(word[i]);
                    count++;
                    i++;
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
            }
            else if(word[i]=='u'){
                if(st.top()=='o'||st.top()=='u'){
                    st.push(word[i]);
                    count++;
                    ans=max(count,ans);
                    i++;
                    
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
            }
        }
       
        return ans;
    }
};