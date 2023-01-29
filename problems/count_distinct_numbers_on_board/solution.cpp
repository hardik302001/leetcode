/*
Assume n is on the board,
n % (n - 1) == 1 if n > 1,
so n - 1 will be on the board,
then n - 2 will be on the board,
same for n - 3,n - 4 .... 3, 2.

So for any n > 1,
2,3,4...n will be on the board finally,
we return n - 1
*/


class Solution {
public:
    int distinctIntegers(int n) {
        return max(1, n-1);
    }
};