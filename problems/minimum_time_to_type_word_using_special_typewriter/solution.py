class Solution:
    def minTimeToType(self, word: str) -> int:
        ans = 0
        word = 'a' + word
        
        n = len(word)
        for i in range(1,n):
            d = abs(ord(word[i]) - ord(word[i-1]))
            # print(d)
            x = min(d,26-d)
            ans = ans + x + 1
        # print()
        return ans