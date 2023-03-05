class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        rep = time//(n-1)
        time = time%(n-1)
        if rep&1:
            return n-time
        else:
            return time + 1