class Solution:
    def canThreePartsEqualSum(self, nums: List[int]) -> bool:
        s = sum(nums)
        n = len(nums)
        if s%3!=0:
            return False
        c1 = 0
        ind1 = -1
        for i in range(n):
            c1+=nums[i]
            if(c1==s//3): 
                ind1 = i
                break
            
        c2 = 0
        ind2 = -1
        for i in range(n-1, -1 ,-1):
            c2+= nums[i]
            if(c2==s//3): 
                ind2 = i
                break
        if ind1==-1 or ind2==-1:
            return False
        
        if ind1+1<ind2:
            return True
        else:
            return False