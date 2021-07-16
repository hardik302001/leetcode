class Solution:
    def insert(self, intervals: List[List[int]], new: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(intervals)):
            if new[1]<intervals[i][0]:
                res.append(new)
                return res + intervals[i:]
            elif new[0]>intervals[i][1]:
                res.append(intervals[i])
            else:
                new = [min(new[0],intervals[i][0]), max(new[1],intervals[i][1])]
        res.append(new)
        return res