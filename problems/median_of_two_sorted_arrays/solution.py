
# 1. sorting n logn

# 2. two pointer : O(n+m)


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        ptr1 = 0 # pointer for nums1
        ptr2 = 0 # pointer for nums2
        ret = [] # list storing elements ascendingly until median
        
        while (ptr1+ptr2 < (len(nums1)+len(nums2)+1)/2):
            
            if ptr1 == len(nums1):
                ret.append(nums2[ptr2])
                ptr2 += 1
                continue
            if ptr2 == len(nums2):
                ret.append(nums1[ptr1])
                ptr1 += 1
                continue
                
            if nums1[ptr1] < nums2[ptr2]:
                ret.append(nums1[ptr1])
                ptr1 += 1
            else:
                ret.append(nums2[ptr2])
                ptr2 += 1
                
        if (len(nums1)+len(nums2))%2 == 0:
            return (ret[-1] + ret[-2]) / 2
        else:
            return ret[-1]
#. Time complexity: In total (m+n)/2 loops, each taking O(1)

