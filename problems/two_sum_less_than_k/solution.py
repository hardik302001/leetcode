class Solution:
    def twoSumLessThanK(self, a: List[int], K: int) -> int:
        a.sort()
        i,j = 0,len(a)-1
        ans = -1
        while i<j:
            if a[i]+a[j]<K:
                ans = max(ans,a[i]+a[j])
                i += 1
            else:
                j -= 1
        return ans