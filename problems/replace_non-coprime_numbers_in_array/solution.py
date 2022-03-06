# https://leetcode.com/problems/replace-non-coprime-numbers-in-array/discuss/1823596/C%2B%2BPython-Stack-%2B-Math
# nice pblm!

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stk = []
        for num in nums:
            stk.append(num)
            while len(stk) > 1 and gcd(stk[-1], stk[-2]) > 1:
                stk.append(lcm(stk.pop(), stk.pop()))
        return stk