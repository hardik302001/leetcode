class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        ans = 0
        a = 0
        b = 0
        
        for i in nums1:
            a^=i
        for i in nums2:
            b^=i
        
        if len(nums1)&1==0 and len(nums2)&1==0:   return 0
        elif len(nums1)&1!=0 and len(nums2)&1==0: return b
        elif len(nums1)&1==0 and len(nums2)&1!=0: return a
        else: return a^b