def toMin(time):
    time = time.split(':')
    res = (60*int(time[0])) + int(time[1])
    return res
    
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        for i, time in enumerate(timePoints):
            timePoints[i] = toMin(time)
        
        res = sys.maxsize
        timePoints.sort()
        for i in range(0, len(timePoints) - 1): #calculate the closest CW distance of each element except last
            res = min(res, (timePoints[i+1] - timePoints[i]))
        
        res = min(res, 60* 24 - (timePoints[-1] - timePoints[0])) #calc final point
        
        return res