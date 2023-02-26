class Solution:
    def isDecomposable(self, s: str) -> bool:
        c = itertools.groupby(s)
        two = 0
        for k, v in c:
            val = len(list(v))
            if val % 3 == 0:
                continue
            elif val % 3 == 2:
                two += 1
                if two >= 2:
                    return False
            else:
                return False
        return True if two == 1 else False