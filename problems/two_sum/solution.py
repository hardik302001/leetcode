# also see : https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/

# see sorting + 2 pointer nlogn approach also..

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            if nums[i] in d:
                return (d[nums[i]] , i)
            else:
                d[target-nums[i]] = i