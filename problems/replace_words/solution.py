class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        d = {}
        for word in dictionary:
            d[word] = word
        ans = []
        for word in sentence.split():
            f = 0
            for i in range(len(word)):
                pre = word[:i+1]
                
                if pre in d:
                    f = 1
                    ans.append(d[pre])
                    break
            if not f:
                ans.append(word)
        
        return " ".join(ans)
            