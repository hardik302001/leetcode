class Solution:
    def alertNames(self, name: List[str], time: List[str]) -> List[str]:
        d = {}
        n = len(name)
        for i in range(n):
            if name[i] in d:
                d[name[i]].append(time[i])
            else:
                d[name[i]] = [time[i]]
        

        res = []
        for ii in d:
            arr = d[ii]
            arr.sort()
            for i in range(len(arr)-2):
                t1 = arr[i]
                t3 = arr[i+2]
                h1, m1 = t1.split(":")
                h2, m2 = t3.split(":")
                if int(h1) + 1 < int(h2): continue
                if h1 == h2: res.append(ii); break
                if m1 >= m2: res.append(ii); break
                    

                
        
        return sorted(res)