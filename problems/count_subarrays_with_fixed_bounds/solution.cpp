
/*

INTUITION

Count the number of subarrays,
using sliding window(three pointers).


EXPLANATION

We maintain a maximum sliding window
with alll elements in range [minK, maxK],
j is the index of leftmost element of the subarray.
i is the index of rightmost element of the subarray.

And we record the index jmin and jmax, where:
jmin is index of last seen A[jmin] = mink
jmax is index of last seen A[jmax] = maxk

Itearte the A[i],
if A[i] == minK, update jmin = i
if A[i] == maxK, update jmax = i

If A[i] not in range of [minK, maxK],
A[i] cannnot be in the subarray,
update j = i + 1.

In the end of each iteration,
the subarray ends at A[i]
the starting element of the subarray,
can be choosen in interval [j, min(jmin, jmax)]
There are min(jmin, jmax) - j + 1 choices,
so we update res += max(0, min(jmin, jmax) - j + 1).


Complexity
Time O(n)
Space O(1)
*/




class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if (num == minK) {
                minFound = true;
                minStart = i;
            }
            if (num == maxK) {
                maxFound = true;
                maxStart = i;
            }
            if (minFound && maxFound) {
                res += (min(minStart, maxStart) - start + 1);
            }
        }
        return res;
    }
};