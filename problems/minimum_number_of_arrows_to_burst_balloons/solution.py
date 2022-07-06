
# same as counting number of non overlapping intervals
# https://leetcode.com/problems/non-overlapping-intervals/

class Solution:
    def findMinArrowShots(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        c = 0
        intervals.sort()
        
        begin = intervals[0]
        for i in range(1, n):
            if intervals[i][0] <= begin[1]:
                c = c + 1
                
                # we consider small interval, after overlap , bcz we need to minimise no of arrows
                if intervals[i][1]>= begin[1]:
                    begin = begin
                else:
                    begin = intervals[i]
            
            
            else:
                begin = intervals[i]

                
        
        return n-c