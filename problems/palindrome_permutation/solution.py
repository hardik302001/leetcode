import collections 
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        n = len(s)
        c = 0
        d = Counter(s)
        for i in d:
            if d[i]&1: c+=1
        return c<=1