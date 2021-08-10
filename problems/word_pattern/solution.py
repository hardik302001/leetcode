#same as isomorphic strings
#Points to be noted:
#compare length, not length of set
#we need bijection, so we need to comapre in d.values also!!
#this is the final code, dont look at previous code!!
#same code goes for ISOMORPHIC STRINGS


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = list(s.split())
        if len(s)==len(pattern):
            d = {}
            for i in range(len(pattern)):
                if pattern[i] not in d:
                    if s[i] not in d.values():      #bijection
                        d[pattern[i]] = s[i]
                    else:
                        return False
                else:
                    if s[i]!= d[pattern[i]]:
                        return False
            return True
        
        
        return False   #for different length
                