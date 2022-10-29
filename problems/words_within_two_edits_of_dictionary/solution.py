# brute force


class Solution:
    def twoEditWords(self, queries: List[str], dic: List[str]) -> List[str]:
        words = []
        for q in queries:
            # hamming distance condition 
            if any(sum(c1 != c2 for c1, c2 in zip(q, d)) <=2 for d in dic):
                words.append(q)
        return words