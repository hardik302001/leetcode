class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        
        n = len(arr)
        l = -1
        r = n
        ans = -1
        while l<r:
            m = (l+r)//2
            if   m==arr[m] : ans = m ; r = m
            elif m>arr[m]  : l = m+1 
            else           : r = m
        return ans