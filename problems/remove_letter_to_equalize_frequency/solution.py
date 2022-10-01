class Solution:
    def equalFrequency(self, word: str) -> bool:


        for i in range(len(word)):
            left = word[0:i] + word[i+1:]
            freq = Counter(left)
            p = set()
            for i in freq:
                p.add(freq[i])
            if len(p) == 1:
                return True
        return False