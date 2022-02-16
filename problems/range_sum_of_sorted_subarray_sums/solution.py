# Time : O(n^2) | Space:O(n)

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        ans = []
        prefix = [0]
        for num in nums:
            prefix.append(prefix[-1]+num)
        n = len(prefix)
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                total = prefix[i] - prefix[j]
                ans.append(total)
        ans.sort()
        return sum(ans[left-1:right])%1000000007
    