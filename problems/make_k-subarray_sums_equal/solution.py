
# https://leetcode.com/problems/make-k-subarray-sums-equal/discuss/3366442/Python-3-Find-Median-of-Each-GCD-Defined-Subarray-(w-Examples)

class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        gcd = math.gcd(n, k)
        ans = 0
        for i in range(gcd):
            tmp = sorted([arr[j] for j in range(i, n, gcd)])
            median = tmp[len(tmp) // 2]
            ans += sum(abs(num - median) for num in tmp)
        return ans