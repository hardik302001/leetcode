class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(set(s)) == len(set(t)):
            m = {}
            for i in range(len(s)):
                if s[i] not in m:
                    m[s[i]] = t[i]
                else:
                    if t[i] != m[s[i]]:
                        return False
            return True
        return False