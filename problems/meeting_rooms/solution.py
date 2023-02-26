class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> int:
        p = []
        for interval in intervals:
            s = interval[0]
            e = interval[1]
            p.append([s,0])
            p.append([e,1])
        p.sort(key = lambda x: (x[0] , -x[1]))  #priority should be time of meeting, and we focus that if start and end time of meeting is same , then consider of ending of meeting first
        pre = 1
        for i in p:
            if i[1]==0:
                if pre==0: return False
                else     : pre = 0
            else:
                if pre==1: return False
                else     : pre = 1
        return True
    
    
    
# ----------------------------------------------------------------------------

# other way of doing same thing
'''
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        for i in range(len(intervals) - 1):
            if intervals[i][1] > intervals[i+1][0]:
                return False
        return True
        
'''