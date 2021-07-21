class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        s1 = "qwertyuiopQWERTYUIOP"
        s2 = "asdfghjklASDFGHJKL"
        s3 = "zxcvbnmZXCVBNM"
        res = []
        for i in words:
            f1 = 0
            f2 = 0
            f3 = 0
            for ii in i:
                if ii in s1:
                    f1 = 1
                elif ii in s2:
                    f2 = 1
                else:
                    f3 = 1
            if f1 + f2 + f3==1:
                res.append(i)
        return res