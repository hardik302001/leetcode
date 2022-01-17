#O(n2)
# https://leetcode.com/problems/longest-palindromic-substring/


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


    
#  other way to do same thing
'''
#O(n2)
# https://leetcode.com/problems/longest-palindromic-substring/

class Solution:
    def countSubstrings(self, S: str) -> int:
        N = len(S)
        ans = 0
        for center in range(2*N - 1):
            left = center // 2
            right = left + center % 2
            while left >= 0 and right < N and S[left] == S[right]:
                ans += 1
                left -= 1
                right += 1
        return ans
'''