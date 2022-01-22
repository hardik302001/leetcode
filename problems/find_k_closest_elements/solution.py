# https://leetcode.com/problems/find-k-closest-elements/discuss/462664/Python-binary-search-with-detailed-explanation
'''
I was also confused by Case 3. Why is that if x is closer to arr[mid], then arr[mid+k] cannot be part of the k elements? Remember:

We are trying to find the start of the final results, not some value in the middle. (<-- explains how we set left and right under the conditionals)
We purposely design the interval arr[mid] < x < arr[mid + k] to have only k-1 elements. (<-- this part is where I forgot)
This means, if x is in the interval arr[mid] < x < arr[mid + k], and let's say x is closer to arr[mid] :

Step 1: Since the interval has only k-1 numbers, the eventually returned k elements will need to include either arr[mid] or arr[mid+k]
Step 2: Since x is closer to arr[mid], then arr[mid] will be added before arr[mid+k], making arr[mid+k] out of the k bound
Step 3: Hence we conclude to skip anything to the right of mid. Anything to the right of mid and to the left of mid+k are potentially just one of the k-1 returned elements following arr[mid] (if it is picked as start), and anything to the right of and including mid+k are just not part of the final answer.
'''

# we know ans would be a segment of size k
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if x <= arr[0]: 
            return arr[:k]
        if x >= arr[-1]:
            return arr[-k:]
        #binary search on what shud be starting point of the segment of size k
        
        left = 0
        right = len(arr) - k # max start point
        while left < right:
            mid = left + (right - left) // 2

            # mid + k is closer to x, discard mid by assigning left = mid + 1
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1

            # mid is equal or closer to x than mid + k, remains mid as candidate
            else:
                right = mid

        # left == right, which makes both left and left + k have same diff with x
        return arr[left : left + k]