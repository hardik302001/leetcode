'''
we are finding longest common substring from the string !
by string matching here so O(n2)

we will optimise it in coming solutions!

'''

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        if s=="":return s
        for i in range(n,0,-1):
            if s[:i]==s[:i][::-1]:
                return s[i:n][::-1] + s
        # return s