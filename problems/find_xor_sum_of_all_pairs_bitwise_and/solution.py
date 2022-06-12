# big thanks to : https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/discuss/1163973/Simple-Shortcut-Explained


class Solution:
    def getXORSum(self, arr1, arr2):
        M = (1 << 30)
        res = [0]*31
        i = 0
        while M:
            c1 = sum(bool(num & M) for num in arr1)
            c2 = sum(bool(num & M) for num in arr2)
            res[i] = (c1 * c2) & 1  # totalcount of set bit in pairs
            i += 1
            M >>= 1
        return sum(bit * (2**i) for i, bit in enumerate(reversed(res)))
    
'''
if we get bitwise OR

  c1o = sum(bool(num & M) for num in arr1)
  c1z = len(arr1) - c1o
  c2o = sum(bool(num & M) for num in arr2)
  c2z = len(arr2) - c2o
  tot = c1o * len(arr2) + c2o * c1z
  res[i] = tot&1

'''