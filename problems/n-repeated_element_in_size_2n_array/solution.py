class Solution(object):
    def repeatedNTimes(self, A): 
        return int((sum(A)-sum(set(A))) // (len(A)//2-1))