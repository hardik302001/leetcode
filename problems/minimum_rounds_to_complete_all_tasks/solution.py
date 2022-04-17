# Intuition : Every number is a sum of 2s and 3s, except 1.

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        d = Counter()
        for i in tasks:
            d[i]+=1
        
        c = 0
        for xx in d:
            i = d[xx]
            if i==1:
                return -1
            else:
                if i%3==0:
                    c+= (i)//3
                else:
                    c+=(1+i//3)
            
        return c
                