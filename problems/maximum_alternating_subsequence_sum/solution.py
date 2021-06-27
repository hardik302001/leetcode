class Solution:
    def maxAlternatingSum(self, A: List[int]) -> int:
        
        
        eve, odd = A[0], 0    # The last index is the maximum result of an even index, and the last index is the maximum result of an odd index
        for a in A[1:]:
            neweve = max(eve, a, odd+a)
            newodd = max(odd, eve-a)
            eve, odd = neweve, newodd
        return max(eve, odd)
        
        