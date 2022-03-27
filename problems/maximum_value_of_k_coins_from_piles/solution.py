# https://binarysearch.com/problems/K-Stack-Pops 
# copied soln ,  dont knwo how to do it

class Solution:
    def maxValueOfCoins(self, stacks: List[List[int]], k: int) -> int:
   
        NINF = float("-inf")
        dp = [NINF] * (k + 1)
        dp[0] = 0

        for stack in stacks:
            P = [0]
            for x in (stack):
                P.append(P[-1] + x)

            for j in range(k, 0, -1):
                for i in range(1, min(j + 1, len(P))):
                    dp[j] = max(dp[j], dp[j - i] + P[i])

        return dp[k]
