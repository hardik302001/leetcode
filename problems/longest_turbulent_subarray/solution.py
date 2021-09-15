class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        if len(A) == 0:
            return 0

        situationOne = 0
        maxLength = 0
        for index in range(len(A) - 1):
            if index % 2 == 1 and A[index] > A[index+1] or \
                index % 2 == 0 and A[index] < A[index+1]:
                situationOne += 1
            else:
                situationOne = 0

            if situationOne > maxLength:
                maxLength = situationOne

        situationOne = 0
        maxLength2 = 0
        for index in range(len(A) - 1):
            if index % 2 == 1 and A[index] < A[index+1] or \
                index % 2 == 0 and A[index] > A[index+1]:
                situationOne += 1
            else:
                situationOne = 0

            if situationOne > maxLength2:
                maxLength2 = situationOne

        return max(maxLength+1, maxLength2+1)