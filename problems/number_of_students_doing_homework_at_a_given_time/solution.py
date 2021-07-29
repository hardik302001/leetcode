class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        c =  0
        l = []
        for i in range(len(startTime)):
            a = startTime[i]
            b = endTime[i]
            l.append([a,b])
        l = sorted(l, key = lambda x: (x[0], x[1]))
        n = len(l)
        p = [0]*(max(endTime))
        for i in l:
            for j in range(i[0],i[1]+1):
                p[j-1] = p[j-1]+1
        if queryTime>max(endTime):
            return 0
        return p[queryTime-1]