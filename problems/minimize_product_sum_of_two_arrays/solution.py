class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        # Sort nums1 in ascending order, and nums2 in
        # descending order.
        nums1.sort()
        nums2.sort(reverse=True)
        
        # Initialize sum as 0.
        ans = 0
        
        # Iterate over two sorted arrays and calculate the 
        # cumulative product sum. 
        for num1, num2 in zip(nums1, nums2):
            ans += num1 * num2

        return ans