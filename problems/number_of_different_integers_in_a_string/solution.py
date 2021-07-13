class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        f = 0
        if    word.isalpha():
            f = 1
        if  f:
            return 0
            
        alp = 'abcdefghijklmnopqrstuvwxyz'
        for i in alp:
            if i in word:
                word = word.replace(i,' ')
                #rint(word)
        print(word)
        word = list(map(int, word.split()))
        print(word)
        if len(word)==0:
            return 0
        s = set(word)
        return len(s)