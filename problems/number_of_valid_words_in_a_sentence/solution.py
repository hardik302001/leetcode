class Solution:
    def countValidWords(self, sentence: str) -> int:
        ans = 0
        for s in sentence.split():
            if any(i in s for i in '0123456789'):
                continue
            if s.count('-') > 1 or s[0] == '-' or s[-1] == '-':
                continue
            if '-' in s:
                x = s.index('-')
                if not s[x-1].isalpha() or not s[x+1].isalpha():
                    continue
            if sum(i in '!.,' for i in s) > 1:
                continue
            if any(i in '!.,' for i in s[:-1]):
                continue
            ans += 1
        return ans