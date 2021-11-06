// same as coin combinations I cses
//https://cses.fi/problemset/task/1635/



#define ll long long

class Solution {
public:
    long long int combinationSum4(vector<int>& c, int target) {
        int n = c.size();

          vector<unsigned int> dp(target+1,0);
          dp[0] = 1;                            //if we have the same number itself
          for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
              if (i-c[j] >= 0) {
                (dp[i] += dp[i-c[j]]);
              }
            }
          }
          return dp[target];
    }
};

//follow up
/*
I think if there are negative numbers in the array, we must add a requirement that each number is only used one time, or either positive number or negative number should be used only one time, otherwise there would be infinite possible combinations.
For example, we are given:
{1, -1}, target = 1,
it's obvious to see as long as we choose n 1s and (n-1) -1s, it always sums up to 1, n can be any value >= 1.

*/