#idea from https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/


class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        
        def solve(arr):
            st = set(arr)
            if len(arr) != len(st): return len(st) == 1 # take care of duplicates
            mx, mn = max(arr), min(arr)
            if (mx - mn)%(len(arr)-1) != 0: return False
            step = (mx - mn)//(len(arr)-1)
            for i in range(mn, mx, step):
                if i not in st:
                    return False
            return True   
        
        
        ans = []
        for i in range(len(l)):
            x = solve(nums[l[i]:r[i]+1])
            ans.append(x)
        return ans