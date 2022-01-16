// https://leetcode.com/problems/best-sightseeing-pair/discuss/1468367/Code-walk-through-O(n)-time-%2B-O(1)-space

//It's similar to Best Time to Buy and Sell Stock, but instead of min price, we track max value, and our max value decays every step due to the distance penalty.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a)
    {
        int n = a.size(), maxScore = 0;
        int maxLeft = a[0] + 0;
        for(int j = 1; j < n; j++) {
            maxScore = max(maxScore, maxLeft + a[j] - j);
            maxLeft = max(maxLeft, a[j] + j);
        }
        return maxScore;
    }
};