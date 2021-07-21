#greedy
class Solution:
    def minDeletions(self, s: str) -> int:
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        a = d.values()
        ans = 0
        if len(a) ==len(set(a)):
            return 0
        se = set()
        for i in a:
            if i not in se:
                se.add(i)
            else:
                while (i in se) and i!=0:
                    i = i -1
                    ans = ans +1
                if i !=0:
                    se.add(i)
        print(se)
        return ans