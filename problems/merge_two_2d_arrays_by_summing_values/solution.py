class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        ans = []
        d1 = {}
        for i in nums1:
            d1[i[0]] = i[1]
        for i in nums2:
            if i[0] in d1:
                d1[i[0]] += i[1]
            else:
                d1[i[0]] = i[1]
        for i in d1:
            ans.append([i , d1[i]])
        ans.sort()
        return ans
