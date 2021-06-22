/*
A bit of an explanation, with an example, just to help myself:

We start from the least significant digit, and traverse the bits. If each digit is larger than the last, there are no digits we can swap to achieve a greater number (return -1). Once we find a digit that we can swap (one that is smaller than the less significant digit before it), then we traverse to its right to find the least significant digit that is greater than it. Since we know that everything to the right of the first digit is in ascending order, the least significant digit is also the smallest digit. Thus, we swap out the first digit with the smallest digit that is also greater than it, guaranteeing that our new number will be greater. However, in order to get the smallest possible number, we still need to reverse the digits to the right, which were in ascending order, so that they will be in descending order, and thus smaller.

Example using 534976:
534976
534976
536974
  |  |
 now 536 is fixed and rest 3 places are variable  536_ _ _
 so to get the next smallest we need to sort the variable digits...
 
 
536479

*/
class Solution{
public:
int nextGreaterElement(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
}
};


