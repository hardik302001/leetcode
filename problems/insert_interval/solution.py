# also see: merge interval



# T.C. : = O(n) 


class Solution:
    def insert(self, intervals: List[List[int]], new: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(intervals)):
            if new[1]<intervals[i][0]:    # before current interval
                res.append(new)
                return res + intervals[i:]
            elif new[0]>intervals[i][1]:   # after current interval
                res.append(intervals[i])
            else:
                new = [min(new[0],intervals[i][0]), max(new[1],intervals[i][1])]  # very important we are updating new here..and not pushing it now , bcz its a case of overlapping intervals
                
        res.append(new) # we have not returned until now , it means new is still left so we push it into result , and thus we now return our res array
        
        return res