


class Solution:
    def exclusiveTime(self, N, logs):
        ans = [0] * N
        stack = []
        prev_time = 0                         #start time of prev log
        
        for log in logs:
            fn, typ, time = log.split(':')
            fn, time = int(fn), int(time)

            if typ == 'start':
                if stack:
                    ans[stack[-1]] += time - prev_time 
                stack.append(fn)
                prev_time = time
            else:
                ans[stack.pop()] += time - prev_time + 1
                prev_time = time + 1                        #important, bcz after end (i.e. time) , ofc start wil be at end + 1, bcz for prev_time we need start time

        return ans