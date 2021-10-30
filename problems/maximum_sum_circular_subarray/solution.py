# https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633401/Kadane-Algorithm-Trick-beats-100-Java-Explained


class Solution:
    def maxSubarraySumCircular(self, a: List[int]) -> int:
        
        def maxsubarraysum(a):
            for i in range(1,len(a)):
                a[i] = max(a[i], (a[i] + a[i-1]))
            return max(a)
        
        b = a[:]
        tot = sum(b)
    
        non_circular_array_max_sum = maxsubarraysum(b)
    
        a = [-1*i for i in a]
        
        minimum_subarray_sum = maxsubarraysum(a)
        
        circular_array_max_sum =  tot + minimum_subarray_sum
        
        if circular_array_max_sum==0:
            return non_circular_array_max_sum
        
#The basic intution is that if circular sum is equal to 0(bcz  tot == -min_subarray_sum ), it means that it did not include any element in max subarray. ( Since min sub array is equal to entire array in this case) and we cant leave subarray as empty..so we choose non_circular_array_max_sum(whatever value be it(bcz we know it will not be non expmty))
        
        return max(non_circular_array_max_sum, circular_array_max_sum)