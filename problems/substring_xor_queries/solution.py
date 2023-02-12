'''
Time O(30N + Q)
Space O(30N)
where N = s.length
'''

class Solution:
    def substringXorQueries(self, s, queries):
        n = len(s)
        seen = defaultdict(lambda: [-1, -1])
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                seen[0] = [i, i]
                continue
            v = 0
            for j in range(i, n):
                v = v * 2 + int(s[j])
                if v > 2 ** 32: break   # halt step
                seen[v] = [i, j]
        return [seen[sec ^ fir] for fir, sec in queries]