class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        newnum = []
        for j in arr:
            x = sum((j >> i) & 1 for i in range(32))
            p = [x,j]
            newnum.append(p)
        newnum.sort()
        ans = []
        for i in newnum:
                 ans.append(i[1])
        return ans
        # return sorted(arr, key = lambda num : (sum((num >> i) & 1 for i in range(32)), num))