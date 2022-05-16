# same as : INTEGER BREAK LC 343

class Solution:
    
    def maxNiceDivisors(self, n: int) -> int:
        m = 1000000007 
        if(n==1): return 1
        if(n==2): return max(n , 1)
        if(n==3): return max(n , 2)
        if(n==4): return 4
        divide = n//3
        remainder=n%3
        if(remainder==0): return (pow(3 , divide , m))%m
        if(remainder==1): return (pow(3 , (divide-1) , m)*4)%m     # n = 7 , bcz 3*3*1 < 3*2*2
        if(remainder==2): return (pow(3 , divide , m)*2)%m       # n = 8 , bcz 3*3*2
        