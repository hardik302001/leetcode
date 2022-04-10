class Solution:
    def calPoints(self, ops: List[str]) -> int:
        s = []
        for i in ops:
            if(i=="C"):
                s.pop()
            elif i=="D":
                t = s.pop()
                s.append(t)
                s.append(2*t)
            elif i=="+":
                t1 = s.pop()
                t2 = s.pop()
                s.append(t2)
                s.append(t1)
                s.append(t1 + t2)
            else:
                s.append(int(i))
    
        return sum(s)
                
                