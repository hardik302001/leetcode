// beautiful problem
// idea : https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/discuss/2897969/C%2B%2B-Simple-greedy-in-O(N)-with-explanation
// FOCUS ON STEP 5 here , we intentionally use element at index 0 , to minimise sum.


// MUST READ point explanation : https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/discuss/2898175/Pigeonhole-with-O(n)-Algorithm

/*
Complexity
Time complexity: O(N)
Space complexity: O(The range of the numbers)
*/


class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        
        vector<int> counts(100005, 0);
        int dominantCnt = 0;
        int dominantNum = -1;
        int involvedCnt = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                counts[nums1[i]]++;
                if (counts[nums1[i]] > dominantCnt) {
                    dominantCnt = counts[nums1[i]];
                    dominantNum = nums1[i];
                }
                involvedCnt++;
            }
        }
        if (dominantCnt > involvedCnt / 2) {
            for (int i = 0; i < n; ++i) {  // starting from index 0 , bcz adding index 0 is priority to minimise sum
                if (nums1[i] != nums2[i] && nums1[i] != dominantNum && nums2[i] != dominantNum) {
                    counts[nums1[i]]++;
                    involvedCnt++;
                    ans += i;
                    if (dominantCnt == involvedCnt / 2) {  // even elements , so we do swapping in pairs
                        return ans;
                    }
                }
            }
            return -1;
        }
        else {   // no dominant element 
                // if even count -> swap in pairs
                // if odd count -> if index 0 is there , use it for minimum sum, swap with index 0
                // if odd count -> index 0 is not there , so add it , now we have even , so swap in pairs
            return ans;
        }
    }
};