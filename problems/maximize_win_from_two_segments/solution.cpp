class Solution
{
public:
    int maximizeWin(vector<int> &nums, int k)
    {
        int n = nums.size(), start = 0, ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            while (nums[i] - nums[start] > k)
            {
                start++;
            }
            ans = max(ans, i - start + 1 + (start > 0 ? dp[start - 1] : 0));
            dp[i] = max((i > 0 ? dp[i - 1] : 0), i - start + 1);
        }
        return ans;
    }
};