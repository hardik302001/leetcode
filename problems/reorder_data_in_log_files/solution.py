class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        n = len(logs)   
        d = []
        l = []
        for i in range(n):
            x = logs[i]
            x = x.split()
            if x[1].isdigit():
                d.append(logs[i])
            else:
                x = logs[i]
                x = x.split()
                p = []
                p.append(x[0])
                p.append(x[1:])
                p.append(i)
                l.append(p)
        # print(l)
        l.sort(key = lambda x:(x[1], x[0]))
        
        ans = []
        for i in l:
            ans.append(logs[i[2]])
        ans.extend(d)
        
        return ans