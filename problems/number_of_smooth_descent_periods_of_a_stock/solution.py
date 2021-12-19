class Solution:
    def getDescentPeriods(self, A: List[int]) -> int:
            cnt = 0 # Initialize result
            n = len(A)
            l = 1


            for i in range(n - 1) :
                if (A[i] - A[i+1])==1:
                    l += 1
                else :
                    cnt += (((l + 1) * l) // 2);
                    l = 1

            if (l > 0):
                cnt += (((l + 1) * l) // 2)

            return cnt