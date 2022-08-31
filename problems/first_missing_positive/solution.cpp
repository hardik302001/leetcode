//courtesy codencode yt


// also see: https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
// also see: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
// also see: https://leetcode.com/problems/find-the-duplicate-number/

// bring nums[i] at its corret position
//[1, 2, 3 ,4 ..., n]

class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {
            int n = nums.size();

            for (int i = 0; i < n; i++)
            {
                while (nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i])
                {
                    swap(nums[i], nums[nums[i] - 1]);
                    // for (auto it: nums)
                    // {
                    //     cout << it << " ";
                    // }
                    // cout << endl;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (nums[i] != i + 1)
                {
                    return i + 1;
                }
            }
            return n + 1;
        }
};