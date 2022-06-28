# also see: https://leetcode.com/problems/minimum-increment-to-make-array-unique/

# also see pq solution: cpp

class Solution:
    def minDeletions(self, s: str) -> int:
        n =len(s)
        d = Counter(s)
        p = list(d.values())
        ss = set()
        ans = 0
        for i in p:
            cur = i
            while (cur in ss) and (cur!=0):
                cur-=1
                ans+=1
            ss.add(cur)
    
        return ans
        