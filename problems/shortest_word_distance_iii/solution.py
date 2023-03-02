
from collections import defaultdict
class Solution:
    def shortestWordDistance(self, words: List[str], word1: str, word2: str) -> int:
        locations = defaultdict(list)
        # Prepare a mapping from a word to all it's locations (indices).
        for i, w in enumerate(words):
            locations[w].append(i)

        loc1, loc2 = locations[word1], locations[word2]
        l1, l2 = 0, 0
        min_diff = 10**12

        # Until the shorter of the two lists is processed
        while l1 < len(loc1) and l2 < len(loc2):
            if loc1[l1]!=loc2[l2]: min_diff = min(min_diff, abs(loc1[l1] - loc2[l2]))
            if loc1[l1] < loc2[l2]:
                l1 += 1
            else:
                l2 += 1
        return min_diff


# space can also be optimised