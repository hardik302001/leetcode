class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        l = list(text.split())
        p = []
       
        for i in brokenLetters:
            p.append(i)
        ans = 0
        sp = set(p)
        # print(l)
        # print(sp)
        for i in l:
            for j in sp:
                if j in i:
                    ans +=1
                    break
                    
         
        return len(l) - ans