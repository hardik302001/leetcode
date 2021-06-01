class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = {}

        
        for i in arr1:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        res = []
        for i in arr2:
            for j in range(d[i]):
                res.append(i)
        a = []
        for i in arr1:
            if i not in arr2:
                a.append(i)
        a.sort()
        res.extend(a)
        return res