# Small time range allows tracking of all available time slots that can be greedily selected via sorting by earliest end time.


class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x: x[1])
        tot = 0
        used = [0] * 2001
        for curr_task in tasks:
            s, e, d = curr_task
            up = sum(used[s:e + 1])
            remain = d - up
            if remain <= 0:
                continue
            else:
                while remain>0:
                    for i in range(e, s-1 , -1):
                        if(used[i] == 0):
                            used[i] = 1
                            remain-=1
                            if remain==0: break
        return sum(used)