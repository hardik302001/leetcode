'''
1. Use set
2. sort and check
3. Use map

'''
'''
class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        nums.sort()
        ans = []
        n = len(nums)
        if n==1:
            ans = []
            ans.append(nums[0])
            return ans
        
        for i in range(n):
            if i==0:
                if nums[i+1]!=nums[i] and nums[i+1]!=nums[i]+1:
                    ans.append(nums[i])
            
            elif i==(n-1):
                if nums[i-1]!=nums[i] and nums[i-1]!=nums[i]-1:
                    ans.append(nums[i])
            else:
                if nums[i]!=nums[i-1] and nums[i]!=nums[i+1] and nums[i-1]!=nums[i]-1 and nums[i+1]!=nums[i]+1:
                    ans.append(nums[i])
        return ans
        
'''

class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        d = {}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        
        for i in d:
            if (i-1) not in d and (i+1) not in d and d[i]==1:
                ans.append(i)
        return ans
        