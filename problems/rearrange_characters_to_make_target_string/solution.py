class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        d = Counter(s)
        m = 100000000000
        for i in target:
            m = min( m , d[i]//target.count(i))
        return m