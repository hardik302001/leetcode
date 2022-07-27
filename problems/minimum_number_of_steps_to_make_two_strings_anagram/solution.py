class Solution:
    def minSteps(self, s: str, t: str) -> int:
        
        d = [0]*26
        
        pos = 0
  
        n = len(s)
        for i in range(n):
            curs = ord(s[i])-ord('a')
            d[curs]+=1
            curt = ord(t[i])-ord('a')
            d[curt]-=1
            
      
        for i in d:
            if i>0:
                pos+=i
                
        # return sum(abs(i) for i in d)//2 + sum(abs(i) for i in d)%2
        return pos