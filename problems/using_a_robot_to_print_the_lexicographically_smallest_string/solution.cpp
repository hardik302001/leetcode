class Solution {
public:
    string robotWithString(string s) {
        stack<char>s1, s2;
        map<char, int>seen1, seen2;
        int n = s.size();
        
        
        // stack1 for popping from front
        // stack2 is secondary stack
        
        for(int i = n-1;i>=0;i--){
            s1.push(s[i]);
            seen1[s[i]]++;
        }
        
        string ans;
        
        
        // explore from a to z bcz we need lexographic smallest
        for(auto ch = 'a';ch<='z';ch++){   // check for all chars 
            
            // priority to take from secondary stack first then start exploring current stack
            // and push redundant elements to secondary stack
            while(s2.size() and s2.top()<=ch){
                auto topa = s2.top();
                if(topa<=ch){
                    s2.pop();
                    seen2[topa]-=1;
                    ans+=topa;
                }else{
                    break;
                }
            }
            
            while(s1.size() and seen1[ch]>0){  // while same element is present in string explore
                auto topa = s1.top();
                s1.pop();
                if(topa==ch){
                    seen1[ch]-=1;
                    ans+= topa;
                }else{
                    seen2[topa]+=1;
                    seen1[topa]-=1;
                    s2.push(topa);
                }
            }
        }
        
        
        // put all elements from secondary stack
        while(s2.size()){
            auto topa = s2.top();
            s2.pop();
            seen2[topa]-=1;
            ans+=topa;
        }
            
        return ans;
        
    }
};