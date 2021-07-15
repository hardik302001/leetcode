#visit word pattern   question on leetcode




class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(set(s)) == len(set(t)):
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