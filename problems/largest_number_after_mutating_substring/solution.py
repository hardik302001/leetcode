class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        res = []
        for i in num:
            res.append(i)
        n = len(num)
        f  = 0
        for i in range(n):
            if change[int(num[i])]>int(num[i]):
                f = 1
                res[i] = str(change[int(num[i])])
            elif change[int(num[i])]==int(num[i]):
                res[i] = str(change[int(num[i])])
            else:
                if f:
                    break
        ans = ''
        for i in res:
            ans = ans + i
        return ans
            