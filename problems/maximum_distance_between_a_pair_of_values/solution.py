class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        i = j = 0
        ans = 0
        while i < m and j < n:
            while j < n and nums1[i] <= nums2[j]: #move j
                ans = max(ans, j - i)
                j += 1
                
            while i < m and j < n and not (nums1[i] <= nums2[j]):  # move i
                i = i + 1
        return ans