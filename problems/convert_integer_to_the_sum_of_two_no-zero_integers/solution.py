class Solution:
    def getNoZeroIntegers(self, n):
        for i in range( 1 , n):
            j = n-i
            if str(i).count('0') or str(j).count('0'):
                continue
            else:
                return [i , j]
