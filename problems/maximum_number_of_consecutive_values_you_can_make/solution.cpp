//  https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/discuss/1118806/Short-and-Easy-w-Explanation-or-Greedy-Approach

	
		
// also see: patching array lc 330


class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {

	sort(begin(coins), end(coins));

	int curSum = 0;

	for(auto& coin : coins)

		if(coin <= curSum + 1) curSum += coin;

		else break;

	return curSum + 1;

}
        

};