class Solution
{
public:
    int subsetXORSum(vector<int>& nums)
    {
        int N = nums.size();
        int numOfSubsets = pow(2, N);
        int result = 0;
        
        // binary representation of subsets help us identify whether to take an element of num or not
        for (int subset = 1; subset < numOfSubsets; ++subset)
        {   int bits = subset;
            int runningXor = 0;
            for (int i = 0; i < nums.size(); ++i){
                if (bits & (1<<i))   // check if ith bit is set in bits or  not [ 0th bit, 1st bit..]
                    runningXor ^= nums[i];//if bit is set, then we consider nums[i] in xor
                
            }
            
            result += runningXor;
        }
        
        return result;
    }
};