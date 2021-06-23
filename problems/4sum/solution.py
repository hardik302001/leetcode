class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        k=len(nums)
        nums.sort()

        res = set()
        for i in range(0,k):
            for j in range(i+1,k):
                start=j+1
                end=k-1
            
                while start < end:
                    cur = nums[i] + nums[j]
                    cur = cur + nums[start] + nums[end]
                    # print(cur)
                    # print(res)
                    if cur==target and (nums[i],nums[j],nums[start],nums[end]) not in res:  
                        res.add((nums[i],nums[j],nums[start],nums[end]))
                        start+=1
                        end-=1
                    elif cur > target:
                        end-=1
                    else:
                        start+=1
        return res