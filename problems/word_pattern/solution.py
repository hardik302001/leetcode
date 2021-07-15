#same as isomorphic strings


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = list(s.split())
        if len(s)!=len(pattern):
            return False
        
        d = {}
        
        for i in range(len(s)):
            if pattern[i] not in d:
                if s[i] not in d.values():
                    d[pattern[i]] = s[i]
                else:
                    return False
            else:
                if s[i]!= d[pattern[i]]:
                    return False
        return True
                