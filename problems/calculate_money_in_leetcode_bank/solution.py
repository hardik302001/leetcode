class Solution:
    def totalMoney(self, n: int) -> int:
        m = 1
        s = 1
        d = 1
        while True:
            if d>=n:
                return s
            for i in range(m+1,m+7,1):
                d = d +1
                s = s + i
                if d>=n:
                    return s
            m =m +1
            s = s + m
            d = d +1
            