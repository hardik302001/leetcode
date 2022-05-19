# https://leetcode.com/problems/3sum-with-multiplicity/


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums.sort()

        res= []
    
        target = 0 
    
        i = 0
        while i< n-2:
            start=i+1
            end=n-1
            
            while start < end:
                cur = nums[i] + nums[start] + nums[end]
                if cur==target and [nums[i],nums[start],nums[end]] not in res: 
                    
                    
                    # repetition check only on start and end , not on i, remember it!!
                    while start < end and nums[start] == nums[start+1]:   
                        start += 1
                    while start < end and nums[end] == nums[end-1]:
                        end -= 1
                    res.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1
                    
                elif cur > target:
                    end-=1
                else:
                    start+=1
            # repetition of first number
            while i+1 < n-2 and nums[i] == nums[i+1]:   
                i += 1
            i+=1
        return res