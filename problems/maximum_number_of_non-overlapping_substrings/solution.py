# https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/744420/C%2B%2BJavaPython-Interval-Scheduling-Maximization-(ISMP)

'''
Why the answer for "abab" is "abab", and not "bab"?
According to condition 2 (see the problem description): a substring containing 'a' must also contain all occurrences of 'a'. So, "bab" is simply not a valid substring. 

For the same reason we have while loop, where it consideres the maximum righmost index of all chars between index b and e, for string starting at index b

Why, we are not updating left index, bcz if we consider updating left index then our string will not start at index b, and there will be repetitive cases..bcz we would have already considered some string string from index beta, where beta<b. 

'''


# read replies to this comment for more info : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/744420/C++JavaPython-Interval-Scheduling-Maximization-(ISMP)/624083


class Solution:
    def maxNumOfSubstrings(self, s):
        fst = { c : i for i, c in reversed(list(enumerate(s))) }
        lst = { c : i for i, c in enumerate(s) }
        
        intervals = []
        for c in set(s):
            b, e = fst[c], lst[c]
            i = b
            while i <= e and b == fst[c]:  # while starting index remains same, consider all elements else break  
                b = min(b, fst[s[i]])
                e = max(e, lst[s[i]])        # update ending index
                i += 1                       # check for all index between the range
            if b == fst[c]:   # if starting index of string is not updated then only consider it
                intervals.append((e, b))
        
        
        intervals.sort()
        ans, prev = [], -1
        for e, b in intervals:
            if b > prev:
                ans.append(s[b:e + 1])
                prev = e
        
        return ans
    
    
# also there is a solution through kosaraju algo , see that also in cpp section, ciao .