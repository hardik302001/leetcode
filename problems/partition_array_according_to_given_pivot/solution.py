class Solution:
    def pivotArray(self, nums: List[int], piv: int) -> List[int]:
        less = []
        eq = []
        more = []
        
        for i in range(len(nums)):
            if nums[i]==piv:
                eq.append(nums[i])
            elif nums[i]>piv:
                more.append(nums[i])
            else:
                less.append(nums[i])
        return list(less + eq + more)