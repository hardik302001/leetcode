class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k==0:
            if nums1==nums2:
                return 0
            else:
                return -1
             
        n = len(nums1)
        c = 0
        p = 0
        ne = 0

            
        for i in range(n):
            d = nums1[i]-nums2[i]
           
            if d%k!=0:
                return -1
            else:
                if d>=0:
                    p +=(abs(d)//k)
                else:
                    ne +=(abs(d)//k)
                    
        if p==ne:
            return ne
        else:
            return -1