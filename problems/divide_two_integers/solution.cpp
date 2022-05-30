/*

The key observation is that the quotient of a division is just the number of times that we can subtract the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12. Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice, it is 1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0). The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0. We are done. In this case, no shift happens. We simply add 1 << 0 = 1 to the answer variable.

This is the full algorithm to perform division using bit manipulations. The sign also needs to be taken into consideration. And we still need to handle one overflow case: dividend = INT_MIN and divisor = -1.

*/


// https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code



class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positiv
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){  // while dividend is greater than or equal to divisor
            int q = 1;
            while(a > (b<<(q)))
                q++;
        
            q--;  // bcz we are one step ahead ...
            
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
};