# Binary search on answer.
# same as koko banana


class Solution:
    def minimumTime(self, time: List[int], tot: int) -> int:
        time.sort()

        # Conisider high as 10 power 14
        # Hey upper bound can be the maxTIme*totalTrips ,and according to given constraints they both can go upto 10^7 , which is 10^7 * 10^7 = 10^14 .
        
        
        lo,hi = 1,1000000000000000
        while lo < hi:
            mid = (lo + hi) // 2
            if self.canDo(mid, time , tot):
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    
    
    def canDo(self,mid, time , tot):                        
        t = 0
        for i in time:
            t += mid//i
            
            if t>=tot:
                return True
        return False