class Solution:
    def splitNum(self, s: int) -> int:
        s = str(s)
        a , b = '' , ''
        f = 0
        for i in sorted(s):
            if f: a+=i
            else: b+=i
            f = 1 - f 
        return int(a) + int(b)