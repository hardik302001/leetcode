//https://leetcode.com/problems/total-hamming-distance/discuss/96243/Share-my-O(n)-C%2B%2B-bitwise-solution-with-thinking-process-and-explanation

//see bit by bit in all nums[i]


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        
        while(true)                  // bit , bit 1... and so on
        {
            int zeroCount = 0;
            int a = 0;
            int b = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                int lsb = nums[i]%2;
                if (lsb) b++;
                else a++;
                
                nums[i] = nums[i] / 2;
            }
            ans += a*b;
            if(zeroCount == nums.size()) return ans;
        }
    }
};