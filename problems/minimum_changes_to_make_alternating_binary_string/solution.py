class Solution:
    def minOperations(self, s: str) -> int:
                #1 -1 1 -1
        m1 = 0  #1  0 1  0
        m2 = 0  #0  1 0  1
        f = 1
        for i in s:
            if f==1:
                if i=="1":
                    m2 = m2 + 1
                else:
                    m1 = m1 + 1
            else:
                if i=="1":
                    m1 = m1 + 1
                else:
                    m2 = m2 + 1
            f = f*-1
        return min(m1,m2)
                    
                    
                    