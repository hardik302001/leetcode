class Solution(object):
    def trailingZeroes(self, n):
        zeroCnt = 0
        while n > 0:
            n = n//5
            zeroCnt += n
        
        return zeroCnt
    
    
'''
5              1
10             2
15             3
20             4
25             6     -> 5 10 15 20 5 5    (bcz 25 is 5*5)




'''