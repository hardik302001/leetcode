# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        l = 1
        r = n
        
        while l<r:
            m = l+(r-l)//2
            if not isBadVersion(m):
                l = m+1
            else:
                r = m  #bcz we need first occurence if bad word
                
        return l