class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n=len(nums)
        nums.sort()

        res = []
        i = 0
        while i< n-3:
            j = i+1
            while j<n-2:
                start=j+1
                end=n-1
            
                while start < end:
                    cur = nums[i] + nums[j] + nums[start] + nums[end]
                    
                    if cur==target and [nums[i],nums[j],nums[start],nums[end]] not in res:
                        res.append((nums[i],nums[j],nums[start],nums[end]))
                        
                        # repetition check only on start and end 
                        while start < end and nums[start] == nums[start+1]:   
                            start += 1

                        while start < end and nums[end] == nums[end-1]:
                            end -= 1
                            
                        start+=1
                        end-=1
                        
                    elif cur > target:
                        end-=1
                    else:
                        start+=1
                
                
                # repetion of 2nd number
                while j+1 < n-2 and nums[j] == nums[j+1]:   
                    j += 1
                j+=1
            # repetition of first number
            while i+1 < n-3 and nums[i] == nums[i+1]:   
                i += 1
            i+=1
        return res