class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        d = Counter()
        for i in tasks:
            d[i]+=1
        
        c = 0
        for xx in d:
            i = d[xx]
            # print(i)
            if i==1:
                return -1
            elif i==2:
                c+=1
            elif i==3:
                c+=1
            else:
                ma = 100000000000
                for x in range(0 , i//3+1):
                    p = i - 3*x
                    if p%2==0:
                        ma = min(ma , x + p//2)
                
                if ma==100000000000:
                    return -1
                else:
                    c+=ma
            
        return c
                