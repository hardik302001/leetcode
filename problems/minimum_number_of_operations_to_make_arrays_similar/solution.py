class Solution:
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        nums.sort()
        target.sort()
        
        e1 = []
        o1 = []
        e2 = []
        o2 = []
        
        c = 0
        for i in range(n):
            if nums[i]&1:
                o1.append(nums[i])
            else:
                e1.append(nums[i])
        for i in range(n):
            if target[i]&1:
                o2.append(target[i])
            else:
                e2.append(target[i])
        
        
        # odd and even difference
        # bcz updating x by +2 or -2 , will keep the parity of x same.
        # so odd x will do operations with other odd's only, same for even's
        
        for i in range(len(e1)):
            d = e1[i]- e2[i]
            if d>0:     c += (d)//2
        
        for i in range(len(o1)):
            d = o1[i] - o2[i]
            if d>0:     c += (d)//2
        return c