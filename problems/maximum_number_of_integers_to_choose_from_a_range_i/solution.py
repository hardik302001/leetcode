class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        s = 0
        c = 0
        i = 1
        ss = set(banned)
        while s<maxSum and i<=n:
            if (i not in ss) and (s + i<=maxSum):
                s+=i
                c+=1
                
            i+=1
        return c