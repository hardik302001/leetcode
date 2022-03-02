class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        ans = [0]*(2051)
        for b, e in logs:
            ans[b] +=1
            ans[e] -=1
        # print(ans[1950:])
        m = 0
        res = -1
        for i in range(1, 2051):
            ans[i] = ans[i-1] + ans[i]
            if(ans[i]>m):
                res = i
                m = ans[i]
        # print(ans[1950:])
        return res