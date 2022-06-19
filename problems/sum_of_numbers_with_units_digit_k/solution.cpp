//. https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168211/C++-or-Short-and-easy-with-math



class Solution {
public:
    int minimumNumbers(int sum, int k) {
        if (sum == 0) return 0;
        for (int i = 1; i <= sum; ++i)
            if ((i * k) % 10 == sum % 10 && i * k <= sum) return i;
        return -1;
    }
};