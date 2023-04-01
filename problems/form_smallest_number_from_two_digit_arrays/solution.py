class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        p = set(nums1)&set(nums2)
        if len(p)>0: return min(list(p))
        else: 
            z = [min(nums1), min(nums2)]
            z.sort()
            return z[0]*10+z[1]