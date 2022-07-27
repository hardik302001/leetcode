# isomrphic strings


class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        n = len(pattern)
        res = []
        def match(word, pattern):
            if len(word) != len(pattern):
                return False
            dir = {}
            for i in range(n):
                w = word[i]
                p = pattern[i]
                
                if w not in dir:
                    if p in dir.values():
                        return False
                    dir[w] = p
                else:
                    if dir[w] != p:
                        return False
            return True

        for w in words:
            if match(w, pattern):
                res.append(w)
        return res
