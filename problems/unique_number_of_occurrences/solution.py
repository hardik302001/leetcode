class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d = Counter()
        for i in arr:
            d[i]+=1
        p = d.values()
        return len(set(p))==len(p)