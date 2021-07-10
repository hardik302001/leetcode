class Solution:
    def palindromeAt(self,s, l, r):    
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]
    
    def longestPalindrome(self, s: str) -> str:
            
        res = ""        
        for i in range(len(s)):        
            odd  = self.palindromeAt(s, i, i)
            even = self.palindromeAt(s, i, i+1)
            res = max(res, odd, even, key=len)
        return res

 

