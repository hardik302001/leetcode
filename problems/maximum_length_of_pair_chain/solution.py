# greedy : O(nlogn)
class Solution:
    def findLongestChain(self, pairs):
        cur, ans = float('-inf'), 0
        for x, y in sorted(pairs, key = lambda x: x[1]):
            if cur < x:
                cur = y
                ans += 1
        return ans
    



# ----------------------------------------------------------------


'''
# similar to LIS
# O(n^2)

class Solution:
    def findLongestChain(self, pairs):
        pairs.sort()
        dp = [1] * len(pairs)

        for i in range(len(pairs)):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)
    
'''