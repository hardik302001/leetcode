#monotonic stack logic!

# also see https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        st = []
        for idx, num in enumerate(nums):
            # pop element from st if last element is greater than the current element
            # and also I have enough elements left such that I can have list of size k
            while st and st[-1] > num and (len(st)-1 + len(nums)-idx >= k):  
                # len(st)-1, bcz that top element will be popped, we would have on eleemet less..and len(nums) - idx will give the remaining elements,                     # including the current element!
                st.pop()
            if len(st) < k:
                st.append(num)
        return st
    
    