// cf 5c
// https://leetcode.com/problems/longest-valid-parentheses/discuss/14355/My-solution-using-one-stack-in-one-pass
// also see: https://leetcode.com/problems/contiguous-array/

class Solution {
public:
     // Using a stack. One pass
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stack.push(i);
            else {
                if (!stack.empty() && s[stack.top()] == '(') {
                    stack.pop();                 //most impo step! bcz we want beginning of subarray to find length of longest valid parantheis
                    
                    int lastPos = -1;           //suppose stack is empty now, we have 0 based indexing, len = i +1 [ == i - (-1) ] 
                                                //else len = i - (start of subarray or top of stack)
                    if (!stack.empty())
                        lastPos = stack.top();
                    int curLen = i - lastPos;
                    maxLen = (maxLen < curLen) ? curLen : maxLen;
                } else
                    stack.push(i);
            }
        }
        return maxLen;
    }
        

};