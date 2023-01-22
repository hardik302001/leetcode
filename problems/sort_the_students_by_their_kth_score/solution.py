class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        
        # return sorted(A, key=lambda a: -a[k])
    
        s = len(score)
        ex = len(score[0])
        p  = []
        for i in range(s):
            p.append([score[i][k] , i])
        p.sort(key = lambda x: (-x[0]))
        
        d = []
        for i in p:
            d.append(i[1])
        
        new = []
        for i in d:
            new.append(score[i])
        
        return new
    
    
    