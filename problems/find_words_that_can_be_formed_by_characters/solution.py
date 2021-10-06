class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        rst, m = 0, [0] * 26
        for i in chars: m[ord(i) - ord('a')] += 1
        for word in words:
            isgood, mm = True, [0] * 26
            for i in word:
                ind = ord(i) - ord('a')
                mm[ind] += 1
                if mm[ind] > m[ind]: isgood = False; break
            if isgood: rst += len(word)
        return rst