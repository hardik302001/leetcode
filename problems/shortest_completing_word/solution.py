class Solution:
    def shortestCompletingWord(self, s: str, words: List[str]) -> str:
        d = Counter()
        for i in s:
            if i.isnumeric():
                continue
            if i==' ':
                continue
            p = i.lower()
            d[p]+=1
        ans = ''
        sz = 10000000000
        
        # print(d)
        for word in words:
            f = 1
            for x in d:
                if word.count(x)<d[x]:
                    # print(x)
                    f = 0
                    break
            if f:
                if sz>len(word):
                    sz = len(word)
                    ans = word
        return ans
                
                
                
            
            