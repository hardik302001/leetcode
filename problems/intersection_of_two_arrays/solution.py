#https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/282372/Java-solution-with-all-3-follow-up-questions




'''
This is a Facebook interview question.
They ask for the intersection, which has a trivial solution using a hash or a set.

Then they ask you to solve it under these constraints:
O(n) time and O(1) space (the resulting array of intersections is not taken into consideration).
You are told the lists are sorted.

Cases to take into consideration include:
duplicates, negative values, single value lists, 0's, and empty list arguments.
Other considerations might include
sparse arrays.


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Time O(NlogN) Space O(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersections;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                intersections.push_back(nums1[i]);
                i++;
                j++;
                while (i < nums1.size() && nums1[i] == nums1[i - 1]) {
                    i++;
                }
                while (j < nums2.size() && nums2[j] == nums2[j - 1]) {
                    j++;
                }
            }
        }
        return intersections;
    }



'''
class Solution(object):
    def intersection(self, nums1, nums2):
        d = {}
        ans = set()
        for i in nums1:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        for i in nums2:
            if i in d:
                if d[i]>0:
                    ans.add(i)
                    d[i]-=1
        return ans

# class Solution:
#     def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         s1 = set(nums1)
#         s2 = set(nums2)
#         return s1&s2