class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closestSum = float('inf')
        nums.sort()
        for i in range(len(nums)):
            lo, hi = i + 1, len(nums) - 1
            while (lo < hi):
                sum = nums[i] + nums[lo] + nums[hi]
                if abs(target - sum) < abs(target- closestSum):
                    closestSum = sum          
                if sum < target:
                    lo += 1
                else:
                    hi -= 1
            if closestSum == target:
                break
        return closestSum