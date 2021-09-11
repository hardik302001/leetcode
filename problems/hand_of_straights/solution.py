class Solution:
    def isNStraightHand(self, nums: List[int], k: int) -> bool:
        
        n = len(nums)
        if n%k==0:
            d = {}
            nums.sort()
            for i in nums:
                if i in d:
                    d[i]+=1
                else:
                    d[i]=1
                    
            l = list(set(nums))
            l.sort()
            for value in l :
                p = d[value]           #first value of the group 
                if p>0:
                    for c in range(k):
                        if ((value + c) in d)   and  d[value + c] >=p:
                            d[value + c]-=p   #bcz atmax p occurence of first eleemnet, so there shud also be atleast p occurence of all other rest elemenets of grp
                        else:
                            return False
                    
            return True
        else:
            return False

