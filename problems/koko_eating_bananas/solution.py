#monotonic function
#binary serach O(nlogn)
#more the maximum value of banana considered, less the number of hours required
#so monotonic, we can apply bs..

#EXACTLY SAME AS :  https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/



# O(NlogM) time，N = len(piles), M = max(piles)
class Solution(object):
    def minEatingSpeed(self, piles, H):
        
        lo,hi = 1,max(piles)
        while lo < hi:
            mid = (lo + hi) // 2
            if self.canEat(mid, piles, H):
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    
    
    def canEat(self,k, piles, H):                         #can eat all
        time = 0
        for i in range(len(piles)):
            time += int(math.ceil(piles[i]/float(k)))
            if time > H: return False
        return True