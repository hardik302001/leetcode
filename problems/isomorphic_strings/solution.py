#same as word pattern question on leetcode
#Points to be noted:
#compare length, not length of set
#we need bijection, so we need to comapre in d.values also!!
#this is the final code, dont look at previous code!!
#same code goes for WORD PATTERN




class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) == len(t):
            m = {} 
            for i in range(len(s)):
                if s[i] not in m:
                    if t[i] not in m.values():    # abba cccc
                        m[s[i]] = t[i]
                    else:
                        return False
                else:
                    if t[i] != m[s[i]]:
                        return False
            return True
        return False