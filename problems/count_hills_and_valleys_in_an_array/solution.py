class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        nums.append(-1)
        p = nums[0]
        l = []
        n = len(nums)
        for i in range(n):
            if p!=nums[i]:
                l.append(p)
                p = nums[i]
        # print(l)
        
        
        c = 0
        for i in range(1 , len(l)-1):
            if l[i]>l[i+1] and l[i]>l[i-1]: c+=1
            elif l[i]<l[i+1] and l[i]<l[i-1]: c+=1
        return c