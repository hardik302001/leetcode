'''
Since the array is already sorted, we can keep two pointers ii and jj, where ii is the slow-runner while j is the fast-runner. As long as nums[i] = nums[j]nums[i]=nums[j], we increment jj to skip the duplicate.

When we encounter nums[j] != nums[i]nums[j] , the duplicate run has ended so we must copy its value to nums[i + 1]nums[i+1]. ii is then incremented and we repeat the same process again until jj reaches the end of array.

'''


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        for i in range(1,len(nums)):
            if nums[i] != nums[count]:
                count +=1
                nums[count] = nums[i]
                
        return count+1