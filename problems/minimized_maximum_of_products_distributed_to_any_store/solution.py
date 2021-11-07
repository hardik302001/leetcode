#monotonic function
#binary serach O(nlogn)
#more the maximum value of product considered, less the number of stores required
#so monotonic, we can apply bs..

#EXACTLY SAME AS :  https://leetcode.com/problems/koko-eating-bananas/submissions/





class Solution:
    def minimizedMaximum(self, n: int, quan: List[int]) -> int:
        lo,hi = max(1,sum(quan)//n) , max(quan)         #low when all elements equal (or) 1     #high can be atmax max(quan) bcz we need to minimise maximum
        while lo < hi:
            mid = (lo + hi) // 2
            if self.canTakeProd(mid, quan, n):
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    
    
    def canTakeProd(self,k, quan, n):                         #if we can take all products
        store = 0
        for i in range(len(quan)):
            store += int(math.ceil(quan[i]/int(k)))    #to conisder how many stores will quan[i] take, if we can have atmost k products in each store
            
            if store > n: return False       #k is too small, less k leads to more number of stores
        return True