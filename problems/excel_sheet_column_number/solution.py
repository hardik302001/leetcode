'''
import string
class Solution:
    def titleToNumber(self, col: str) -> int:
        alp = string.ascii_uppercase
        col = col[::-1]
        ans = 0
        for i in range(len(col)):
            ans = ans + pow(26,i)*(alp.index(col[i])+1)
        return ans
'''    

class Solution:
    def titleToNumber(self, col: str) -> int:
        alp = string.ascii_uppercase
        ans = 0
        for i in col:
            ans = 26 * ans + alp.index(i)+1
        return ans