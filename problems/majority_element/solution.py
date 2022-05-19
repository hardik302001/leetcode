#O(n) moore algo   O(1) space

class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = -1

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
             
'''
# o(nlogn)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)//2]
    
    
# O(n) : map  => two pass O(n) space
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d:
                d[i]+=1
            else: d[i]= 1
        for i in d:
            if d[i]>(len(nums)//2):
                return i

    
        
# O(n) : map  => two pass O(n) space
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element_dict = {}
        
        for num in nums:
            if num not in element_dict:
                element_dict[num] = 0. 
            element_dict[num] += 1
        
        major_e = 0
        max_val = 0 
        for key, val in element_dict.items():
            if val > max_val:
                max_val = val 
                major_e = key 
        
        return major_e
'''