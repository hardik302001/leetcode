"""
        2 pointers, left and right, such that right = n - left - 1
        i.e., they are equidistant from both ends
        
        in a palindromic arrangement of s, s[left] == s[right]

        if s[left] and s[right] are not equal:
        1. from j = right, check whether there is an element equal to s[left]. 
           decrement j until an equal element is not found
        2. similarly, i = left, check whether there is an element equal to s[right].
           increment i until an equal element is not found
        3. now we need to decide to either move element at left to element at i, or
           element at right to element at j
        4. calculate the cost for both possibilities, (i - left and right - j)
        5. choose the minimum and move those elements by adjacent swaps
        This algo works for both odd and even
        
        what if we have odd n..so we have one extra character
        s = "caabb"
        So if we try to make left chacter ie "c" equal to "b", we will need to go till 4th position , 3 swaps
        if we try to make right chacter i.e. "b" equal to "c" we need to come till first position so , 4 swaps
        minium is 3 swaps, so after 3 swaps we will have s = "bcaab" , 
        
        now our left is "c" and right is "a", again we do same thing 
        and we get minimum as 1 swap , so s = "bacab"...
        Thus this strategy works, bcz for odd count chacater we will eventually find the opposite direction character , before its 
        actual position , like we found another "b" (4th position) before the actual 5h position "b" ,....but we will not find another "c" [odd chacarcter , because it doesnot exists..]...so will swap more to reach there...
        
"""
    
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        n = len(s)
        s = list(s)
        res = 0
        
        for left in range(n//2):
            right = n - left - 1
            if s[left] != s[right]:
                i = left
                j = right
                
                while s[left] != s[j]:
                    j -= 1
                    
                    
                while s[right] != s[i]:
                    i += 1
                    
                    
                if right - j < i - left:
                    res += right - j
                    for x in range(j, right):
                        s[x] = s[x+1]
                else:
                    res += i - left
                    for x in range(i, left, -1):
                        s[x] = s[x-1]
                        
        return res
        