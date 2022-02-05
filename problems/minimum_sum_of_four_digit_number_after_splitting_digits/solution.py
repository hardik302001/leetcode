class Solution:
    def minimumSum(self, num: int) -> int:
        m = 1000000000000
        p = []
        num= str(num)
        for i in num:
            p.append(i)
        p.sort()
        n1 = int(p[0])*10 + int(p[3])
        n2 = int(p[1])*10 + int(p[2])
        
        return n1 + n2
    