// SEE ALL PREVIOUS CODES FOR TOP DOWN APPROACH





//top down


class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long long modValue = 1e9 + 7;
        long long dp[3] = {0, 0, 0};
        //dp[0] rerpesnts no of subsequences of 0
        //dp[1] rerpesnts no of subsequences of 0 1
        //dp[2] rerpesnts no of subsequences of 0 1 2
        for (int i = 0; i < nums.size(); ++i)
        {
            switch (nums[i])
            {
            case 0:
            {
                dp[0] = (dp[0] + dp[0] + 1) % modValue;
                // If we find new 0 then three types of subsequences exist
                // 1. Old ones(hence once dp[0])   =>  we ignore current char
                // we consider current char , so 2 cases
                // 2. New ones formed by pushing a 0 to old ones(hence another dp[0])
                // 3. One zero itself (hence +1)    => our subseq starts from this current 0
                break;
            }
            case 1:
            {
                dp[1] = (dp[1] + dp[0] + dp[1]) % modValue;
                // If we found a 1 then three types of subsequences exist
                // 1. The already present subsequences till that index(hence once dp[1])    =>  we ignore this cuuret char 1
                // if we consider currrent char 1, then 2 cases: 
                // 2. The new subsequnces formed by pushing a 1 to all the subsequnces of 0(hence dp[0])  , this 1 is pushed after all subseq ending with 0 
                // 3. The new subsequences formed by pushing a 1 to all the old subsequences of 01(hence the last dp[1]) , or pushed after all 1,so its dp[1] only
                break;
            }
            case 2:
            {
                dp[2] = (dp[2] + dp[1] + dp[2]) % modValue;
                // If we found a 2 then three types of subsequences exist
                // 1. The already present subsequences till that index(hence once dp[2])  => we ignore this char 2
                // if we consider currrent char 2, then 2 cases:
                // 2. The new subsequnces formed by pushing a 2 to all the subsequnces of 01(hence dp[1]), push curr char 2 after all prev subseq ending at 1
                // 3. The new subsequences formed by pusing a 2 to all the old subsequences of 012(hence the last dp[2]) all subseq ending at 2, so it will be dp[2]
                break;
            }
            }
        }
        return dp[2];
    }
};