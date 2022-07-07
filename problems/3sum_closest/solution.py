# it gives fucking TLE, mfs uupdated the tcs
# see cpp solution 

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 1000000000000
        n = len(nums)
        for i in range(n-2):
            l = i+1
            r = n-1
            while l<r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if abs(cur_sum - target) < abs(ans - target):
                    ans = cur_sum
                
                if cur_sum==target:
                    return target
                elif cur_sum>target:
                    r-=1
                else:
                    l+=1
                # print(cur_sum)
        return ans
                
                