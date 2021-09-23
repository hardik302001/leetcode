class Solution(object):
    def breakPalindrome(self, palindrome):
        n = len(palindrome)
        new_pal = list(palindrome)
        for  i in range(n//2):
            if new_pal[i] != "a":
                new_pal[i] = "a"
                return "".join(new_pal)
        
        if len(new_pal) == 1: return ""
        new_pal[-1] = "b"
        return "".join(new_pal)