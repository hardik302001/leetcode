class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++) //check for all possible perfect squares less than i, and choose minimum of them
            {
                cntPerfectSquares[i] = min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1); // +1 bcz we are conisdering it
            }
        }
        
        return cntPerfectSquares.back();
    }
};