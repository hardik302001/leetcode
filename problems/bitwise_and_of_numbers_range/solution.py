#https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/593317/Simple-3-line-Java-solution-faster-than-100

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        #he trick here is that :
        #Bitwise-AND of any two numbers will always produce a number less than or equal to the smaller number.
        
        
        while right>left:
            right = right & (right-1)
        
        
        return right&left