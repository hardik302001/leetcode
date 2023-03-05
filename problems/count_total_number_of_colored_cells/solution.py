'''
1 4 8 12


1 5 13 

'''

class Solution:
    def coloredCells(self, n: int) -> int:
        if n==1: return 1
        else : return 1 + 2*(n)*(n-1)