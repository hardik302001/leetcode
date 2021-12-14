
# exactly same as https://leetcode.com/problems/find-the-most-competitive-subsequence/submissions/
# just replace k by (n-k)
# removing k elements == left with (n-k) elemnts
# also convert to string after converting the integer as we want smallest possible integer after removing k digits from num(see output is string.


class Solution:
    def removeKdigits(self, nums: str, k: int) -> str:
        n = len(nums)
        
        st = []
        for idx, num in enumerate(nums):
            # pop element from st if last element is greater than the current element
            # and also I have enough elements left such that I can have list of size k
            while st and st[-1] > num and (len(st)-1 + len(nums)-idx >= (n-k) ):  
                # len(st)-1, bcz that top element will be popped, we would have on eleemet less..and len(nums) - idx will give the remaining elements,                     # including the current element!
                st.pop()
            if len(st) < (n-k):
                st.append(num)
        return str(int("".join(st))) if st else "0"
    
    # also keep in mind, it shud be st[-1] > num , not st[-1] >= num... why?
    # bcz it would not be lexographically smaller then, we would remove small elements from beginning, but we need them 
    # see this tc =>    "112" , k = 1
    # if we remove equal elements we would remove second "1" and we would be forves to take last "2", to complete (n-k) elements, that would not be             lexographicallly smaller, we would try to take as much loe equal elements in beginning as possible!
    