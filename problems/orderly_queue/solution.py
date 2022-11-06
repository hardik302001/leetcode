'''
If k = 1, only rotations of s are possible, and the answer is the lexicographically smallest rotation.
If k > 1, any permutation of s is possible, and the answer is the letters of s written in lexicographic order.

'''

class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k==1:
            n = len(s)
            p = s + s
            m = 'z'*(n)
            for i in range(n):
                news = p[i:i+n]
                m = min(news , m)
            return m
        else:
            s = sorted(s)
            return ''.join(s)
            