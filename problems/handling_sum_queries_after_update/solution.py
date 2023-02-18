# courtesy  : https://leetcode.com/problems/handling-sum-queries-after-update/discuss/3201936/Python-Convert-to-binary-and-use-XOR


class Solution:
    def handleQuery(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums1)
        bitnum = int(''.join([str(n) for n in nums1]), 2)
        # bi = bin(bitnum)[2:]
        # count = bi.count('1')                # gives tle
        count = bitnum.bit_count()
        ans = []
        sums = sum(nums2)
        for q in queries:
            if q[0] == 1:
                l, r = q[1], q[2]
                temp = (1 << (n - l)) - (1 << (n - r - 1))
                bitnum ^= temp
                # bi = bin(bitnum)[2:]
                # count = bi.count('1')
                count = bitnum.bit_count()
            elif q[0] == 2:
                p = q[1]
                sums += p * count
            else:
                ans.append(sums)
        return ans
