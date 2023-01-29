/*
total - no colllison = atleast one collision

Each monkey can move in the clockwise or counter-clockwise direction,
so 2 choices for each of n monkeys.

There are 2 ^ n number of ways.
If all monkey move in clockwise direction, no collision.
If all monkey move in counter-clockwise direction, no collision.
All other ways, collision happens.

So we need to return (2 ^ n - 2) % mod,
*/


class Solution {
public:
    int monkeyMove(int n) {
        long res = 1, base = 2, mod = 1e9 + 7;
        while (n > 0) {
            if (n % 2)
                res = res * base % mod;
            base = base * base % mod;
            n >>= 1;
        }
        return (res - 2 + mod) % mod;
    }
};