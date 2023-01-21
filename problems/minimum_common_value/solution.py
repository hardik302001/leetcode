class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        m = len(nums1)
        n = len(nums2)
        nums1.sort()
        nums2.sort()
        i = 0
        j = 0
        
        ans = -1
        while i<m and j<n:
            if nums1[i]==nums2[j]:
                ans = nums1[i]
                return ans
            elif nums1[i]>nums2[j]:
                j+=1
            else:
                i+=1
        return ans