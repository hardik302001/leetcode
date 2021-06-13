import string
alphabets = string.ascii_lowercase


class Solution:

    def makeEqual(self, words: List[str]) -> bool:
        res = ""
        if len(words)==1:
            if len(set(words))==1:
                return True
            else:
                return False
            
        for i in words:
            res = res + i
        ans = []
        # print(res)
        s = set(res)
        for i in s:
            ans.append(res.count(i))
        print(ans)
        l = len(words)
        su = 0
        for i in ans:
            if i%l!=0:
                return False
            else:
                su = su + i//l
        return True
                
        