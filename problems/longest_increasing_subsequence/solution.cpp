// leetcode.com/problems/longest-increasing-subsequence/discuss/74848/9-lines-C%2B%2B-code-with-O(NlogN)-complexity
// binary search O(nlogn) solution, better than O(n2) dp soln
// follow it for future LIS ques

// also see prev dp soln





class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
          vector<int> res;

          vector<int> parent(nums.size());
          int last = -1;
          for (int i = 0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i], [&nums](int x, int y) {
              return nums[x] < y;
            });
            if (it == res.end()) {
              parent[i] = (res.empty()) ? -1 : res.back();
              last = i;

              res.push_back(i);
            }
            else {
              parent[i] = (it == res.begin()) ? -1 : *(it - 1);

              *it = i;      
            }
          }

          int m = res.size();
          vector<int> lis(m);

          while (last != -1) {
            lis[--m] = nums[last];
            last = parent[last];
          }

          return res.size();
        }
};