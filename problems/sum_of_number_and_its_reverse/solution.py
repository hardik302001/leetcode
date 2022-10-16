class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
    	### make sure to check num as well (for case num=0), so we go from 0 to num+1
        
        
        for n in range(0, num + 1):
            strN = str(n)		### convert int to string
            strR = strN[::-1]	### reverse the digits
           
            if int(strN)+int(strR)==num:
                return True
        return False