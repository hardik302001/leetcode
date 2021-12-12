'''
Suppose we have a decreasing sequence followed by a greater number. For example [5, 4, 3, 2, 1, 6] then the greater number 6 is the next greater element for all previous numbers in the sequence.
We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than stack.top() we pop all elements less than x and for all the popped ones, their next greater element is x.
For example [9, 8, 7, 3, 2, 1, 6]. The stack will first contain [9, 8, 7, 3, 2, 1] and then we see 6 which is greater than 1 so we pop 1 2 3 whose next greater element should be 6.

'''

# DECREASING STACK  LEFT TO RIGHT
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cache, st = {}, []
        for i in range(len(nums2)):
            x = nums2[i]
            
            while st and st[-1] <= x:
                cache[st.pop()] = x
            st.append(x)
            # print(st)
        result = []
        for x in nums1:
            if x in cache:
                result.append(cache[x])
            else:
                result.append(-1)
        return result







