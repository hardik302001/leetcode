# happy coding


# rep * q == extension * p, for meeting at corner

class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        rep = 1       # repetition of rays
        ext = 1       # extension in vertical direction
        
        while rep*q != ext*p:
            rep+=1
            ext = (rep*q)//p
        
        print(rep,ext)
        
        if rep%2==0:
            return 2
        else:
            if ext%2==1:
                return 1
            else:
                return 0
        
        
        