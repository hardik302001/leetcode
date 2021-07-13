class Solution:
    def maxSubArray(self, a: List[int]) -> int:
        size = len(a)
        max_so_far = a[0]
        max_ending_here = 0
     
        for i in range(0, size):
            max_ending_here = max_ending_here + a[i]
            if max_ending_here < 0:
                max_ending_here = 0
         
            # Do not compare for all elements. Compare only     
            # when  max_ending_here > 0
            elif (max_so_far < max_ending_here):
                max_so_far = max_ending_here
        if max_so_far <0:
            return max(a)
        return max_so_far