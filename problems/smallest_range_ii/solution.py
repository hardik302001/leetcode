# “Sort the vector.
# Assuming there is a point, on the left of the point, all elements add K, on the right of the point, all elements subtract K, check each possible point. (a point is between two numbers).
# Cause there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K), the first one is on the left of the current point (A[i] + K is the last element of the first segment), the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment).
# For the first segment, the smallest element is left, the largest is A[i] + K; For the second segment, A[i + 1] - K is the smallest element, the largest is right. Thus, for each point, the largest element should be either A[i] + K or right, the smallest element should be either left or A[i + 1] - K.”
# Here is my contribution by provding a Python code:


# also see: https://leetcode.com/problems/smallest-range-i/


class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        if len(A) == 1:return 0
        res = A[-1] - A[0]
        for i in range(len(A)-1):
            this_max = max(A[i]+K, A[-1]-K)
            this_min = min(A[0]+K, A[i+1]-K)
            res = min(res, this_max - this_min)
        return res