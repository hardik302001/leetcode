class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        p = set(words1)
        q = set(words2)
        r = p&q
        # print(r)
        ans = 0
        for i in r:
            if words1.count(i)==1 and words2.count(i)==1:
                ans = ans +1
        return ans