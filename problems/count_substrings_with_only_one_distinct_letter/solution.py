class Solution:
    def countLetters(self, S: str) -> int:
        S +=('#')
        total = left = 0
        for right in range(len(S)):
            if S[left] != S[right]:
                len_substring = right - left
                # more details about the sum of the arithmetic sequence:
                # https://en.wikipedia.org/wiki/Arithmetic_progression#Sum
                total += (1 + len_substring) * len_substring // 2
                left = right
        return total
