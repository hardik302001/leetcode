class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        while m > 0 and n > 0:
            if nums1[m-1] >= nums2[n-1]:
                nums1[m+n-1] = nums1[m-1]
                m -= 1
            else:
                nums1[m+n-1] = nums2[n-1]
                n -= 1
        #if nums1 is already traversed fully , then we are left with only elements from nums2
        #so fir nums2 we need to travers the nums2 array, and put all left elements back into the nums1 array
        if n > 0:
            nums1[:n] = nums2[:n]