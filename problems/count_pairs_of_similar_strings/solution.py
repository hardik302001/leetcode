# hashing with bitmask

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        c = 0
        d = {}
        for word in words:
            bitmask = 0
            for i in word:
                bitmask |= (1<<(ord(i)-ord('a')))
            if bitmask in d:
                d[bitmask]+=1
            else:
                d[bitmask] = 1
        for i in d:
            c+= d[i]*(d[i]-1)//2
        return c
                            