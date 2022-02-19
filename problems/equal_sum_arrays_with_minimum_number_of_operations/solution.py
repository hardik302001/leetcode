'''

# O(nogn)
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1)
        s2 = sum(nums2)
        n1 = len(nums1)
        n2 = len(nums2)
        if n1>n2:
            if 6*n2 < n1: 
                return -1
        if n2>n1:
            if 6*n1 < n2: 
                return -1
            
        if sum(nums1) < sum(nums2): nums1, nums2 = nums2, nums1
        s1, s2 = sum(nums1), sum(nums2) # s1 >= s2
        if s1==s2: return 0
        
        nums1.sort()
        nums2.sort()
        
        i = len(nums1)-1
        j = 0
        ans = 0
        
        while i>=0 or j<=len(nums2)-1:
            if s1>s2:
                if nums1[i]-1 >= 6 - nums2[j]:         # decrease nums1[i] to 1
                    ans = ans + 1
                    s1 = s1 - (nums1[i]-1)
                    i = i - 1
                
                else:
                    ans = ans + 1
                    s2 = s2 + (6 - nums2[j])
                    j = j + 1
            else:
                break
            # print(s1, s2)
        return ans
    
'''  

# O(n): Counting sort
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1)
        s2 = sum(nums2)
        n1 = len(nums1)
        n2 = len(nums2)
        if n1>n2:
            if 6*n2 < n1: 
                return -1
        if n2>n1:
            if 6*n1 < n2: 
                return -1
            
        if sum(nums1) < sum(nums2): nums1, nums2 = nums2, nums1
        s1, s2 = sum(nums1), sum(nums2) # s1 >= s2
        if s1==s2: return 0

        diff = s1 - s2
        counts = [0] * 6
        for x in nums1:
            counts[x-1] += 1
        for x in nums2:
            counts[6-x] += 1

        updates = 0
        for x in range(5, 0, -1):
            used = min(counts[x], ceil(diff / x))
            updates += used
            diff -= used * x
            if diff <= 0:
                break

        return updates

