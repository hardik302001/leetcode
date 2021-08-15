class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        for i in range(1,n,2):
            nums[i],nums[i-1] = nums[i-1],nums[i]
        # print(nums)
        # f = 0
        # for i in range(1,n-1):
        #     if (nums[i-1] + nums[i+1])/2==nums[i]:
        #         f = 1
        #         break
        # if f:
        #     print("NO")
        # else:
        #     print("YES")
        return nums