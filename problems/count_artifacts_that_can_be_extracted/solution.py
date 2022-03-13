class Solution:
    def digArtifacts(self, n: int, art: List[List[int]], dig: List[List[int]]) -> int:
        
        s = set()
        for x,y in dig:
            s.add((x, y))
        
        count = 0
        for a,b,c,d in art:
            
            ans = 1
            for i in range(a, c+1):
                for j in range(b , d+1):
                    p = (i,j) in s
                    ans = ans&p
            count+=ans
        
        
        return count