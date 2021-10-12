# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        s = 1
        e = n
        
        while s<e:
            m = (s+e)//2
            if guess(m)==0:
                return m
            elif guess(m)>0:
                s = m+1
            else:
                e = m
        return s