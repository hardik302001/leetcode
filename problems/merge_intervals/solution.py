# also see: insert interval
# https://leetcode.com/problems/insert-interval/



# TC: O(nlogn) , SC  = O(n)
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()          #starting time
        merged = []
        merged.append(intervals[0])
        for i in range(1,len(intervals)):
            previous_end = merged[-1][1]
            current_start = intervals[i][0]
            current_end = intervals[i][1]
            if previous_end >= current_start: # overlap
                merged[-1][1] = max(previous_end,current_end)     #either current end can be less / more than prev end, so we take max of both
            else:
                merged.append(intervals[i]) #no overlap
                    
        return merged

                    