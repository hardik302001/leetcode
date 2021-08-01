class Solution:
    def minimumPerimeter(self, need: int) -> int:
        a = 12
        b = 1
 
        while True:
            tot = a*b*b   #12*(i)^2
            need = need-tot 
            if need<=0:
                break
            b = b +1
          
        return b*8