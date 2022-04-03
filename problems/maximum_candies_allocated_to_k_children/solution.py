class Solution:
    def maximumCandies(self, cand: List[int], k: int) -> int:
        if k>sum(cand):
            return 0
        else:
            def do(mid , cand, H):                      
                c = 0
                for i in cand:
                    c+= (i)//mid
                
                return c>=H
            
            lo,hi = 1,sum(cand)+1
            while lo < hi:
                mid = (lo + hi) // 2
                if do(mid, cand, k):
                    lo = mid+1
                else:
                    hi = mid
            return lo-1

        
'''

Maximise the minimum
on valid , lo = mid + 1 , return (lo - 1)
Similar to : https://leetcode.com/problems/maximum-running-time-of-n-computers/        
        
'''