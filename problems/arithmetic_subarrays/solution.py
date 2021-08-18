#idea from https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/


class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        
        def solve(arr):
            m = min(arr)
            gap = (max(arr) - m) / (len(arr) - 1)
            if gap == 0: return True
            s = set(num - m for num in arr)
            return len(s) == len(arr) and all(diff % gap == 0 for diff in s)
        
        ans = []
        for i in range(len(l)):
            x = solve(nums[l[i]:r[i]+1])
            ans.append(x)
        return ans