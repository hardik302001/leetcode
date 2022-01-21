class Solution:
    def minOperationsMaxProfit(self, customers: List[int], bc: int, rc: int) -> int:
        c = 0
        ans = [0,-1]
        tot = 0
        wait = 0
        for i in customers:
            c = c + 1
            wait = wait + i
            cur = min(4 , wait)
            wait = wait - cur
            tot = tot + cur * bc - rc
            if tot > ans[0]:
                ans[0] = tot
                ans[1] = c
        while wait>0:
            c = c + 1
            cur = min(4 , wait)
            wait = wait - cur
            tot = tot + cur * bc - rc
            if tot > ans[0]:
                ans[0] = tot
                ans[1] = c
        
        return ans[1]