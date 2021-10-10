class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        p = list(set(nums1)& set(nums2))
        q = list(set(nums2)& set(nums3))
        r = list(set(nums3)& set(nums1))
        return list(set(p + q + r))