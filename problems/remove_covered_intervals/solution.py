# very similar to merge intervals

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: (x[0], -x[1]))
        n = len(intervals)
        ans = 0
        merge = [intervals[0]]
        
        for i in range(1, n):
            prebeg = merge[-1][0]
            preend = merge[-1][1]
            curbeg = intervals[i][0]
            curend = intervals[i][1]
        
            
            if prebeg<=curbeg and curend<=preend:
                ans = ans +1
            else:
                merge.append(intervals[i])
        # print(merge)
        return n - ans