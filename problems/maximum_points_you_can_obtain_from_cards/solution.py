# minimise (n-k)

class Solution:
    def maxScore(self, arr: List[int], k: int) -> int:
        
        l = 0
        s = 0
        n = len(arr)
        if n==k:
            return sum(arr)
        
        ans = 10000000000000
        for r in range(n):
            s+=arr[r]
            if r-l+1==(n-k):
                ans = min(ans , s)
                s-=arr[l]
                l+=1
        # print(ans)
        return sum(arr)-ans
        