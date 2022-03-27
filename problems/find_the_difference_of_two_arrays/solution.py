class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        p1 = set()
        p2  = set()
        for i in nums1:
            if i not in nums2:
                p1.add(i)
        for i in nums2:
            if i not in nums1:
                p2.add(i)
        return [list(p1), list(p2)]