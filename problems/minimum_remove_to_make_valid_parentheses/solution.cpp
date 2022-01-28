
//also see https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
//https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/
//SEE PREV SOLN:below

//in this approach we are avoiding stack, and doing 2 traversals, 
//first from beginning 
//second from end, and we are doing the same thing that we did in previous soln, ples see that also(marking invalid chars)


class Solution {
public:
    string minRemoveToMakeValid(string s){
        int cnt=0;
        for(char &c: s){
            if(c=='(') cnt++;
            else if(c==')')
                if(cnt==0) c='*';
                else cnt--;
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else if(s[i]=='(')
                if(cnt==0) s[i]='*';
                else cnt--;
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};


//also see https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
//https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/


/*
APPROACH 1
Here, we will use a stack for checking the validity of parentheses, and later remove the indexes of invalid parentheses from the string s. Thanks @harmxnkhurana for the suggestion of directly marking the invalid parentheses in string s rather than redundant storing it in a different vector.

First, iterate the string s and mark the index of those characters which need to be removed to make it parentheses string using a special symbol '#'.
Here, a stack is used for finding the valid pair of parentheses, and while doing so also mark the indexes of invalid parentheses in s.
Finally, iterate s again and append non-marked symbol (#) to ans.
COMPLETE CODE

*/

/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int>st; // helper stack for finding matching parentheses
        
        for(int i=0;i<s.length();++i){
            if(s[i]=='('){ // for open parentheses push into stack
                st.push(i);
            }
            else if(s[i]==')'){ // for closing parentheses
                // if no matching previous open parentheses found, we need to remove the index of that open parentheses from "s" so for now we are marking it with special character '#'
                if(st.empty()){ 
                    s[i]='#';
                }
                else{
                    // if matching open parentheses found remove that from the stack
                    st.pop();
                }
            }
        }

        // if stack is not empty, that means it contains open parentheses indexes which don't have any matching closing parentheses
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#'){ // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};

*/