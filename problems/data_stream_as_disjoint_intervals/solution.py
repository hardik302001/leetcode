class SummaryRanges(object):
    def __init__(self):
        self.intervals = []

    def addNum(self, val):
        # find location
        low, high = 0, len(self.intervals) 
        while low < high:
            mid = (low + high) // 2
            elem = self.intervals[mid]
            if elem[0] <= val <= elem[1]:
                return
            elif elem[0] > val:
                high = mid 
            else:
                low = mid + 1

        # insert the interval
        pos = low
        self.intervals.insert(pos, [val, val])

        # merge with next interval
        if pos + 1 < len(self.intervals) and val == self.intervals[pos + 1][0] - 1:
            self.intervals[pos][1] = self.intervals[pos + 1][1]
            self.intervals[pos + 1:pos + 2] = []

        # merge with prev interval
        if pos - 1 >= 0 and val == self.intervals[pos - 1][1] + 1:
            self.intervals[pos - 1][1] = self.intervals[pos][1]
            self.intervals[pos:pos + 1] = []

    def getIntervals(self):
        return self.intervals