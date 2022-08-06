class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        d = {}
        for v, w in items1:
            d[v] = w
        for v, w in items2:
            if v in d:
                d[v]+=w
            else:
                d[v] = w
        ans = []
        for i in d:
            ans.append([i, d[i]])
        ans.sort()
        return ans