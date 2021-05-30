class Solution(object):
    def isMonotonic(self, A):
        if A[0] <= A[-1]:
            A = A[::-1]
        
        # Expected A is decreasing order
        for i in range(1, len(A)):
            if A[i-1] < A[i]:
                return False
        
        return True