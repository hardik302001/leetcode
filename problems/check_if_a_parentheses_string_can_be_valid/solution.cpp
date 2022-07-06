// go solve it first below question, then come here


//also see very similar ques : https://leetcode.com/problems/valid-parenthesis-string/submissions/


class Solution {
public:
    bool canBeValid(string s, string locked) {
        string p;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(locked[i]=='1'){
                p += s[i];
            }
            else{
                p += '*';            // * tells, it can be changed to '(' or ')'
            }
        }
        stack<int>open , star;
        for(int i = 0;i<n;i++){
            if(p[i]==')'){
                if(!open.empty()){      // use open to balance close
                    open.pop();
                }   
                else if(!star.empty()){  // use star to convert to open and balance with close
                    star.pop();
                }
                else{
                    return false;   /// no choice, we r left with extra closed, so unbalanced, so fuck off
                }
            }
            else if(p[i]=='('){
                open.push(i);
            }
            else{
                star.push(i);
            }
        }
        
        
        // now we dont have extra closed,, but we may have extra open, lets see what can be done with them!
        
        while(!open.empty()){
            if(!star.empty()){   // we use star to convert to close, to balance extra opens
                if(star.top()>open.top()){   // but star shud occur after open, bcz star would be closed now
                    star.pop();
                    open.pop();
                }
                else{
                    return false;  // else fuck off, we have extra open, those stars are of no use to alance the top most open
                }
            }
            else{
                return false;
            }
        }
        
        
        
        // now we are left with only star, so we have to do their pairing, so they shud be even....
        // return answer on that basis now
        return star.size()%2==0;
        

    }
};