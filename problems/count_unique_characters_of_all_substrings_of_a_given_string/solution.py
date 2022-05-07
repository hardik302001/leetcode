# occurence barrier on both side, bcz we want unique, so we consider unique occurence as current element and put barrier on both side.


# s = "aba"
'''
for every index, we consider prev and next occurence of that chacrter in that string(prepending and appening in beg and end)
s = "a aba a"
       |

so c+= (1)*(3)

next index

s = "b aba b"
        |
c+= (2)*(2)

next index
s = "a aba a"
         |

so c+= (3)*(1)

c = 10



'''


# also see:  https://leetcode.com/problems/total-appeal-of-a-string/submissions/


class Solution:
    def uniqueLetterString(self, s: str) -> int:
        d = {}
        n = len(s)
        for i in range(n):
            if s[i] not in d:
                d[s[i]] = [-1]
            d[s[i]].append(i)
        
        for i in d:
            d[i].append(n)
        
        c = 0
        for i in d:
            l = d[i]
            for x in range(1 , len(l)-1):
                c+= (l[x]-l[x-1]) * (l[x+1]-l[x])
        return c
    
    
    