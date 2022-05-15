class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        p = []
        prev = words[0]
        p.append(words[0])
        n = len(words)
        for i in range(1 , n):
            x = prev
            y = words[i]
            xx = ''.join(sorted(x))
            yy = ''.join(sorted(y))
            if xx!=yy:
                p.append(y)
                prev = y
        return p