class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        prefix_sum = [0, A[0]]
        for num in A[1:]:
            prefix_sum.append(prefix_sum[-1] + num)
        # print(prefix_sum)
        
        result = L_max = M_max = 0
        
        # L before M
        for i in range(L+M, len(prefix_sum)):
            L_sum = prefix_sum[i-M] - prefix_sum[i-M-L]
            # print("L ",L_sum)
            M_sum = prefix_sum[i] - prefix_sum[i-M]
            # print("M ",M_sum)
            L_max = max(L_max, L_sum)
            result = max(result, L_max + M_sum)
        print()
        # M before L
        for i in range(L+M, len(prefix_sum)):
            M_sum = prefix_sum[i-L] - prefix_sum[i-M-L]
            # print("M ",M_sum)
            L_sum = prefix_sum[i] - prefix_sum[i-L]
            # print("L ",L_sum)
            M_max = max(M_max, M_sum)
            result = max(result, M_max + L_sum)
            
        return result