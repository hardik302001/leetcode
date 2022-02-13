#  https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766752/C%2B%2B-or-Easy-Sorting

# dry run for first tc

class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        
        if len(set(beans))==1:
            return 0
        n = len(beans)
        s = sum(beans)
        ans = 10**12
        beans.sort(reverse = True)
        
        p = [0]*n
        ans = min(ans , s- beans[0])
        for i in range(1, n):
            p[i]=p[i-1] + (beans[i-1]-beans[i])*(i+1)
            ans = min(ans , s - beans[i]*(i+1))
        return ans