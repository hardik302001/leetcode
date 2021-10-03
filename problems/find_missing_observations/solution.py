class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        x = (mean)*(m+n) - sum(rolls)
        
        ans = [0]*n
        mid = x//n
        ext = x%n
        for i in range(n):
            ans[i] = ans[i] + mid
        i = 0
        while ext:
            ans[i] += 1
            ext = ext - 1
            i = i +1
        
        for i in ans:
            if i>0 and i<=6:
                continue
            else:
                return []
        return ans