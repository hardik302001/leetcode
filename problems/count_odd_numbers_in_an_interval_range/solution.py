class Solution:
    def countOdds(self, low: int, high: int) -> int:
        d = high - low
        if d&1:
            return (d+1)//2
        else:
            if low&1:
                return d//2+1
            else:
                return d//2