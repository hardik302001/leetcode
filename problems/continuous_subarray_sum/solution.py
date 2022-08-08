# for more similar ques see: https://leetcode.com/problems/subarray-sum-equals-k/
# exactly same as: https://leetcode.com/problems/subarray-sums-divisible-by-k/
# there we needed count , in tis question we need length



class Solution:
    def checkSubarraySum(self, A: List[int], K: int) -> bool:
        
        ans = 0
        d = {}
        d[0]  = -1         #for length we do -1 as index
        len_A = len(A)
        acc = 0        
        for i in range(len_A):
            acc += A[i]       
            key = acc % K
            
            if key in d:
                ans = max(ans, i - d[key])
            else:
                d[key] = i         #updating indexes
            
            
        return ans>=2