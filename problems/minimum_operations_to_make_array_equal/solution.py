class Solution:
    def minOperations(self, n: int) -> int:
        arr = [2*i+1 for i in range(n)]
        ans = 0
        for i in range(n//2):
            ans = ans + (arr[n-i-1]  - arr[i])//2
        return ans
        