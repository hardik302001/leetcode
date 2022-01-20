#monotonic function
#binary serach O(nlogn)
#more the maximum value of banana considered, less the number of hours required
#so monotonic, we can apply bs..

#EXACTLY SAME AS :  https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/



# O(NlogM) time，N = len(piles), M = max(piles)
class Solution(object):
    def minEatingSpeed(self, piles, H):
        ans = -1
        lo,hi = 1,max(piles)+2
        while lo < hi:
            mid = (lo + hi) // 2
            if self.canEat(mid, piles, H):
                ans = mid
                hi = mid
            else:
                lo = mid + 1
        return ans
    
    
    
    def canEat(self,k, piles, H):                         #can eat all
        time = 0
        for i in range(len(piles)):
            time += ((piles[i]+k-1)//k)
            if time > H: return False
        return True