class Solution(object):
    def validMountainArray(self, A):

        if len(A) < 3:
            return False
        left = 0
        for i in range(len(A)-1):
            if A[i+1] <= A[i]:
                left = i
                break
        right = 0
        for i in range(len(A)-1, 0, -1):
            if A[i-1] <= A[i]:
                right = i
                break
        if left == right and left > 0 and right+1 < len(A):
            return True
        return False