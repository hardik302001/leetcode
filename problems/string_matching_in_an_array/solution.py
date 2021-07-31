class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        s = set(words)
        for  i in s:
            ep = set()
            ep.add(i)
            p = s - ep
            # print(p)
            for j in p:
                if i in j:
                    # print(i,j)
                    ans.append(i)
                    
        return set(ans)