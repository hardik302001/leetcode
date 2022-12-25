# binary search on answer

class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        s = set(price)
        if len(s)<k:
            return 0
        ar = list(s)
        ar.sort()
        n = len(ar)
        l = 0
        h = 10**10
        ans = 0
        while l<h:
            mi = (l+h)//2
            co = 1
            f = 0
            prev = ar[0]
            for i in range(1, n):
                if (ar[i] >= (prev + mi)):
                    co += 1
                    if (co == k):
                        f = 1
                        break
                    prev = ar[i]
            if f:
                ans =mi
                l = mi+1
            else:
                h = mi
        return ans
                