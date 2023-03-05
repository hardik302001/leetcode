class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        merge = []
        merge.append(ranges[0])
        for i in range(1 , len(ranges)):
            if ranges[i][0]<= merge[-1][1]:
                merge[-1][1] = max(merge[-1][1], ranges[i][1])
            else:
                merge.append(ranges[i])
        sz = len(merge)
        return pow(2, sz , 1000000007)