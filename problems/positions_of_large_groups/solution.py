class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ans = []
        beg = 0
        end = 0
        prev = s[0]
        c = 0
        s = s + '#'
        n = len(s)
        for i in range(n):
            if s[i]!=prev:
                if c>= 3:ans.append([i-c ,i-1])
                c = 1
                prev = s[i]
            else:
                c +=1
        return ans