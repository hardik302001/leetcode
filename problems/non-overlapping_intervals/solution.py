# similar ques..merge interval  https://leetcode.com/problems/merge-intervals/
# insert interval

# [1, 2] and [2, 3] are non overlapping

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x : x[0])
        counter = 0
        begin = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] < begin[1]: #overlap ho gaya
                counter += 1 # dono mei se aek ho htna hoga , lets see kisko hatayenge
                begin = begin if begin[1] <= intervals[i][1] else intervals[i] 
                # agar begin(1) less than hai interval(i).end se, uska matlab interval(i) ko hata do! kyuki kya pata interval(i) , interval (i+1) ke saath overlap kr de ...toh hume wha bhi hatana pdega...but we have to minimise, so begin = begin hi reh gya ...
                
                # we will remove bade wala, so that in future wo kisi aur ke saath overlap na ho..
                # in other case , if begin(1), interval(i).end se bhi jyda hai...toh begin ko hatao...else wo overlap krega iske jyda chance hai...
            else:
                begin = intervals[i]     # no overlap , so move on

        return counter
