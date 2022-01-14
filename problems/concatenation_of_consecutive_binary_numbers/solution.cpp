/*
If we have A = 1 and B = 2, and we want to concat their binary representation, we can shift A to the left the "number of spaces" that B it is going to occupy in its binary representation, for example:
If I have (1) and want to concat with (10), we should shift (1) to the left 2 times and then make an OR between them:

100 | 010 = 110


*/

// tc : O(n)

class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res = 0;
        int bitLength = 1;
        int nextIncrease = 2;
        
        for (int i = 1; i <= n; i++) {
            if (i == nextIncrease) {  // bitlength in O(1), you can use log(i)-log(2)+1 also
                nextIncrease *= 2;
                bitLength++;
            }
            
            res = (res << bitLength) | i;
            res %= 1000000007;
        }
        
        return int(res);
    }
};


// if yo calculate length of i by traversing, then it is O(nlogn)