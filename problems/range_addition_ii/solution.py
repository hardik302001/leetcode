class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        r_min=m
        c_min=n
        for i in ops:
            if i[0]<r_min:
                r_min=i[0]
            if i[1]<c_min:
                c_min=i[1]
        return r_min*c_min
    
#we need to consider the most common area