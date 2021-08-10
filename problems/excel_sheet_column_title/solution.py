# https://leetcode.com/problems/excel-sheet-column-title/discuss/51404/Python-solution-with-explanation



class Solution:
    def convertToTitle(self, c: int) -> str:
        ans = ''
        alp = string.ascii_uppercase
        while c>0:
            y = (c-1) % 26        #y will lie between 0 to 25
                            # c-1 to avoid the case for Z, if we directly do we wont get Z ever!
            c = (c-1) // 26      #to move one step ahead 
            ans = alp[y] + ans    #to avoid reverse 
        
            
        return ans