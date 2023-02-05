class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        vowel = ['a','e','i','o','u']
        p = [0]*(n+1)
        ans = -1
        for i in range(n):
            x = words[i]
            if x[0] in vowel and x[-1] in vowel:
                p[i+1] = 1
        for i in range(1,n+1):
            p[i]+=p[i-1]
      
        res = []
        for q in queries:
            aa = q[0]
            bb = q[1]
            res.append(p[bb+1]-p[aa])
        return res