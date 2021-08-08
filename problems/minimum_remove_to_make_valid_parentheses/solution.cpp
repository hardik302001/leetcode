
//also see https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
//https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/
//SEE PREV SOLN

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
