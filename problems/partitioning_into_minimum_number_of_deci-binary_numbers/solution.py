class Solution:
    def minPartitions(self, s: str) -> int:
        ans = 0
        p = list(s.split('0'))
        for i in p:
            if len(i)>0:
                ans = max(ans, int(max(i)))
            
        return ans