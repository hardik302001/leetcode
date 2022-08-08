# exactly same problem: https://leetcode.com/problems/subarray-sum-equals-k/
# exactly same problem: https://leetcode.com/problems/count-number-of-nice-subarrays/


class Solution:
    def numSubarraysWithSum(self, p: List[int], k: int) -> int:
        n = len(p)
        d = {}
        d[0] = 1
        s = 0
        count = 0
        for i in range(len(p)):
            s += p[i]
            if s-k in d: # --- I
                count += d[s-k]
               # or return True
               # or return indicies

               # add sum to frq dict
            if s in d:
                d[s] += 1 # --- II
            else:
                d[s] = 1
        return count
