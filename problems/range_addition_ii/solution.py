class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        a = m
        b = n
        for i in ops:
            a = min(a, i[0])
            b = min(b, i[1])
        return a*b