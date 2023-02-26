class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        lo, hi = 0, n
        banned = set(banned)
        while lo < hi: 
            mid = lo + hi + 1 >> 1
            total = mid*(mid+1)//2
            for x in banned: 
                if x <= mid: total -= x
            if total <= maxSum: lo = mid
            else: hi = mid-1
        return lo - sum(x <= lo for x in banned)