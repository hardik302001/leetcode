//ALSO SEE PYTHON CODE: replace ' )) ' by ' ] ' and solve for ' ( ' and ' ] '  rather than '(' and '))'
//SEE previous STACK SOLUTION ALSO
//COURTESY : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/1394902/C%2B%2B-or-With-and-Without-Stack-or-Clear-and-detailed-step-by-step-explanation

//very nice explanation
//very impo solution
//



//NON STACK SOLUTION
//Time O(n), space O(1)
class Solution {
public:

    int minInsertions(string s) {
        //Let open be the number of open brackets in the stack which did not get equivalent close brackets to balance.
        // openneeded be the number of ( needed (Found when stack was empty)
        // closeneeded be the number of ) needed 
        int open = 0; 
        int openneeded = 0;
        int closeneeded = 0;
        
        for(int i = 0; i<s.size(); i++){
            
            //For open brackets
            if(s[i]=='(')
                open++;
            
            //For close brackets
            else if(s[i]==')') {
                
                //If next char is also a ')' , check if an open bracket was encountered before and has not yet been balanced or not. If yes, decrement the number of open brackets. 
                if( i+1<s.length() and s[i+1]==')'){
                    if(open==0) openneeded++;
                    else open--;                   //bcz s[i-1] == "("..see bottom for more info
                    i++;
                }
                // If next char is a (
                else{
                    if(open==0){
                        openneeded++;
                        closeneeded++;
                    }
                    else {
                        open--;                   //bcz s[i-1] == "("..see bottom for more info
                        closeneeded++;
                    }
                }
            }
        }
        
        int total = 2*open + openneeded + closeneeded;
        return total; 
		}
};

/*
Whenever we get ')' at index i , and we also have ')' or '(' at index (i+1) AND stack is not empty , so by default we have '(' at index (i-1). Why is it so?
Let's prove it by contradiction, let us assume we have ')' at index (i-1) . So our current sequence would look like " ) ) ) " or " ) ) ( " for index (i-1) , (i) , (i+1) respectively. So the thing here to notice is that we have already encountered " ) ) " at index (i-1) and index i, it means we would have already considered this case in previous step, as stack is empty , and current index element is "(" and for next index we have "(" so we should consider inserting an open bracket and we would add it 1 to our answer.

So it means if we are having ')' at index i , and ')' or '(' at index (i+1) AND stack is not empty, then we would only have '(' at (i-1) because we have not considered that case till now. I hope it was clear.

*/