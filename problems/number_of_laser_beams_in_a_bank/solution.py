class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        c = []
        for i in bank:
            cc = i.count('1')
            if cc!=0:
                c.append(cc)
        ans = 0
        for i in range(1,len(c)):
            ans = ans + c[i]*c[i-1]
        return ans