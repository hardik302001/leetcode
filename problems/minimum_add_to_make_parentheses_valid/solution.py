class Solution:
    def minAddToMakeValid(self, s: str) -> int:
           
        missing =left  =0        
        for i in s:
            if i == '(':
                left+=1
            else:
                if left> 0:
                    left -=1
                else:
                    missing+=1
        return missing+left