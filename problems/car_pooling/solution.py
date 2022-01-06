#also see cpp solution , thats good maybe

#INTERVAL SOLUTION
# code is same as neetcode yt, meeting room 2
# considering 2 array for start and end
class Solution:
    def carPooling(self, trips: List[List[int]], capacity : int) -> bool:
        start_timings = sorted( [(trip[1], trip[0]) for trip in trips] )
        end_timings = sorted( [(trip[2], trip[0]) for trip in trips] )

        passengers = 0
        start = end = 0
        while( start < len(trips) ):
            if start_timings[start][0] < end_timings[end][0]:
                passengers += start_timings[start][1]
                start += 1
            else:
                passengers -= end_timings[end][1]
                end += 1
         
            
            if passengers > capacity:
                return False

            # print(passengers, start_timings[start][0], end_timings[end][0])
            
        return True
    
# \U0001f447 i guess it is better solution

# considering only one array for start and end
# idea same as https://leetcode.com/problems/two-best-non-overlapping-events/

# class Solution:
#     def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
#         cur = 0
#         a = []
#         for trip in trips:
#             s = trip[1]
#             e = trip[2]
#             c = trip[0]
#             a.append([s, True, c])
#             a.append([e, False, c])
#         a.sort()
#         for i in a:
#             if i[1]==True:       #start
#                 cur = cur + i[2]
#             else:                #end
#                 cur = cur - i[2]
#             if cur>capacity:
#                 return 0
#         return 1


'''

Meeting rooms 2 
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],…] (si < ei), find the minimum number of conference rooms required.
For example, Given [[0, 30],[5, 10],[15, 20]], return 2.

#see neetcode yt 
# 2 array for start and end, and do 2 pointer 
class Solution:
  def minMeetingRooms(self, intervals: List[List[int]]) -> int:
    n = len(intervals)
    ans = 0
    starts = []
    ends = []

    for start, end in intervals:
      starts.append(start)
      ends.append(end)

    starts.sort()
    ends.sort()
    
    s = 0
    e = 0
    ans, count = 0,0
    
    while s<len(intervals):
        if starts[s]<end[e]:         #another meeting started
            s = s + 1
            count += 1
        else:                       # one of the meeting ended
            e = e +1
            count -= 1
        ans = max(ans, count)

    return ans
    


# single array solution for strat and end
# idea same as https://leetcode.com/problems/two-best-non-overlapping-events/
class Solution:
    def minMeetingRooms(self, intervals):
        # Write your code here
        cur = 0
        m = 0
        a = []
        for trip in intervals :
            s = trip[0]
            e = trip[1]
            
            a.append([s, True])
            a.append([e, False])
        a.sort()
        for i in a:
            if i[1]==True:       #start
                cur = cur + 1
            else:                #end
                cur = cur - 1
            m = max(m , cur)
        return m
''' 