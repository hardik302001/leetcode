# We can either increase sum of nums1 or sum of num2
# If we want to increase sum of nums1, we will select subarray from i to j with maximum sum of nums2[i] - nums1[i];
# If we want to increase sum of num2, we will select subarray from i to j with maximum sum of nums1[i] - nums2[i];

# Time Complexity -> O(N)
# Space Complexity -> O(1)
class Solution:
    def kadane(self , a,size):
            max_so_far = -maxsize - 1
            max_ending_here = 0
            start = 0
            end = 0
            s = 0

            for i in range(0,size):

                max_ending_here += a[i]

                if max_so_far < max_ending_here:
                    max_so_far = max_ending_here
                    start = s
                    end = i

                if max_ending_here < 0:
                    max_ending_here = 0
                    s = i+1
            return [max_so_far , start , end]    # maximum subarray sum exists from index start to index end
        
        
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        dif1 , dif2 = [] , []
        n = len(nums1)
        for i in range(n):
            dif1.append(nums1[i]-nums2[i])
            dif2.append(nums2[i]-nums1[i])


		# base case: if no swapping done.
        ans = max( sum(nums1) , sum(nums2))
        
        
        # find answer after swapping eleemnts of nums2
        s1 , x1 , y1 = self.kadane(dif1 , n)     
        if s1<=0:
            pass
        else:
            cur = 0
            for i in range(n):
                if x1<= i<=y1:         # swap elements from index start to index end
                    cur+=nums1[i]
                else:
                    cur+=nums2[i]
            ans = max( ans , cur)

        # find naswer after swapping elements of nums1
        s2 , x2 , y2 = self.kadane(dif2 , n)
        if s2<=0:
            pass
        else:
            cur = 0
            for i in range(n):
                if x2<= i<=y2:          # swap elements from index start to index end
                    cur+=nums2[i]
                else:
                    cur+=nums1[i]
            ans = max( ans , cur)
            
        return ans