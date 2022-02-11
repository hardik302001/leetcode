# exactly same as : https://leetcode.com/problems/decode-string/

class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        st = []
        
        cur = ""
        
        for i in s:
            if i=='(':
                st.append(cur)
                cur = ""
            elif i==')':
                topa = st.pop()
                cur = topa +  cur[::-1]
                
            else:
                cur = cur + i
        
        return cur
    
