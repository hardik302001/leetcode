#O(n2)
# https://leetcode.com/problems/longest-palindromic-substring/
#see first submission also


class Solution:
    def countSubstrings(self, s: str) -> int:
        def palindromeAt(s, l, r):
            ans = 0
            while l >= 0 and r < len(s) and s[l] == s[r]:
                ans = ans + 1
                l -= 1
                r += 1
            return ans
    
        res = 0        
        for i in range(len(s)):        
            odd  = palindromeAt(s, i, i)
            even = palindromeAt(s, i, i+1)
            res = res + (odd + even)
        return res

 

