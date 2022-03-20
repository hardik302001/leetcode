# https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/901271/C%2B%2BJavaPython-One-pass-Clean-and-Concise-Strictly-O(N)


class Solution(object):
    def minDominoRotations(self, A, B):
        n = len(A)
        cntA = [0] * 7
        cntB = [0] * 7
        cntSame = [0] * 7
        for i in range(n):
            a, b = A[i], B[i]
            cntA[a] += 1
            cntB[b] += 1
            if a == b: cntSame[a] += 1
                
                
        ans = n
        for v in range(1, 7):
            if cntA[v] + cntB[v] - cntSame[v] == n:
                minSwap = min(cntA[v], cntB[v]) - cntSame[v]
                ans = min(ans, minSwap)
                
                
        return -1 if ans == n else ans