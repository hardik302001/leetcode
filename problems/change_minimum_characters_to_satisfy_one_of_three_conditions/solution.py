# Try every letter to make it as the separated letter.
# For example, if we choose c as separated letter,
# less_a is the cost to make all letters in a be less than c and all letters in b be larger and equal to c.

# Time: O(A + B)
# Space: O(1)



# see this force approach : https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/discuss/1032135/C%2B%2B-Easy-to-understand-Brute-force-O(A-%2B-B)-Time-O(1)-Space

import collections
import string
class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        counter_a = collections.Counter(a)
        counter_b = collections.Counter(b)
        less_a, less_b, unique = float('inf'), float('inf'), float('inf')
        accu_a, accu_b = 0, 0
        
        for c in string.ascii_lowercase:
            unique = min(unique, len(a) + len(b) - counter_a[c] - counter_b[c])  #when all char in a and b are equl to char 'c' , third operation
            
            if c > 'a':   # bcz we cant we all char less than 'a' in string a
                less_a = min(less_a, len(a) - accu_a + accu_b)
                less_b = min(less_b, len(b) - accu_b + accu_a)
            accu_a += counter_a[c]   # pefix sum, we dont want to calcualte how many of them are possible occurence for char less than current char c in string a
            accu_b += counter_b[c]
            
            
            
        return min(less_a, less_b, unique)