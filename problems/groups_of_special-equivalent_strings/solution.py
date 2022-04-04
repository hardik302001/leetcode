class Solution:
    def numSpecialEquivGroups(self, words: List[str]) -> int:
        s = set()
        
        for word in words:
            e = []
            o = []
            for i in range(len(word)):
                if i&1:
                    o.append(word[i])
                else:
                    e.append(word[i])
            e.sort()
            o.sort()
            p = ''.join(e) + ''.join(o)
            
            s.add(p)
        
        return len(s)