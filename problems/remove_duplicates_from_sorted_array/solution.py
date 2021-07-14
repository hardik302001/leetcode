'''
Since the array is already sorted, we can keep two pointers ii and jj, where ii is the slow-runner while j is the fast-runner. As long as nums[i] = nums[j] , we increment jj to skip the duplicate.

When we encounter nums[j] != nums[i] , the duplicate run has ended so we must copy its value to nums[i + 1]. ii is then incremented and we repeat the same process again until jj reaches the end of array.

'''


# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         count = 1
#         for i in range(1,len(nums)):
#             if nums[i] != nums[count-1]:
#                 nums[count] = nums[i]
#                 count+=1
                
#         return count
    

#THIS CODE IS GENERALISED VERSION FOR ANY K, rather than atmost  one occurence or rather than atmost 2 occurence, for more info visit remove-duplicates-from-sorted-array-ii
    
class Solution:
    def removeDuplicates(self, nums):
        slow, fast = 1, 1

        while fast < len(nums):
            if nums[slow - 1] != nums[fast]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow