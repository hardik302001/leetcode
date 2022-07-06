class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            int left = 0, right = n - 1;
            int res = 0;
            int maxLeft = 0, maxRight = 0;
            while (left <= right)
            {
                if (height[left] <= height[right])   // it means height[left] is the deciding factor, bcz it have small size
                {
                    if (height[left] >= maxLeft)
                    {
                        maxLeft = height[left];  // maxleft is to stop water from flowing on left side
                    }
                    else
                    {
                        res += maxLeft - height[left];
                    }
                    left++;
                }
                else   // it means height[right] is the deciding factor, bcz it have small size
                {
                    if (height[right] >= maxRight)
                    {
                        maxRight = height[right];  // stop water form flowing on right side
                    }
                    else
                    {
                        res += maxRight - height[right];
                    }
                    right--;
                }
            }
            return res;
        }
};