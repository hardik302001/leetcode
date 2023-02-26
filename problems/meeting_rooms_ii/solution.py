class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        p = []
        for interval in intervals:
            s = interval[0]
            e = interval[1]
            p.append([s,0])
            p.append([e,1])
        p.sort(key = lambda x: (x[0] , -x[1])) 
        # priority should be time of meeting, and we focus that if start and end time of meeting is same , then consider of ending of meeting first
        
        ans = 0
        c = 0
        for i in p:
            if i[1]==0:
                c+=1
            else:
                c-=1
            ans = max(ans , c)        
        return ans
    