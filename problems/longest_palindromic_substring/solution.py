class Solution:

    def longestPalindrome(self, s: str) -> str:
        def palindromeAt(s, l, r):    
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l+1:r]
    
        res = ""        
        for i in range(len(s)):        
            odd  = palindromeAt(s, i, i)
            even = palindromeAt(s, i, i+1)
            res = max(res, odd, even, key=len)   #or update start and end according to lengthof odd and even...and then print final res as substring withs tart and end as corner indexes
        return res

 

