/*

Another explanation,
Assume diff -> [3, -4, 5, 1, -2]
Let's say we start with some 'X' as the starting element.
According to diff; arr[1] will be X + 3; { arr[1] - arr[0] = 3 => arr[1] - X = 3 => arr[1] = X + 3 }.
arr[2] will be X - 1; { arr[2] - arr[1] = -4 => arr[2] - X - 3 = -4 => arr[2] = X - 1 };
Similarly, arr[3] will be X + 4, and so on.

so arr {i.e. hidden sequence} will be [X, X + 3, X - 1, X + 4, X + 5, X + 3];
Now, you observe here, if choose some X, it can be some maximum X + 5 & some minimum X - 1;
Knowing these; you can easily loop over and count for all possible X's and see if X + 5 <= upper & X - 1 >= lower.
*/


// Logic 
// Let's say we take a value X as start element
// Now we keep adding elements of the differences to the value X. 
// With every index, diff keeps accumulating
// We need to find the minimum and maximum difference from the start value. 

// For all values in the given range [lowerBound , upperBound], we check if it is possible to have a values with (val-minDiff) and (val+maxDiff)

// For example : [1,-3,4] , lowerbound=1, upperbound=6
// if X is start value, then array elemnts can be represented as
// [X, X+1, X+(1-3), X+(1-3+4)] = [X, X+1, X-2, X+2]
// minDiff = -2
// maxDiff = +2
// Checking for values in range [1,6] for which [val+mindiff, val+maxdiff] are also in given range

// (1) - (1-2, 1+2) - (-1, 3) - not in range
// (2) - (2-2, 2+2) - (0, 4) - not in range
// (3) - (3-2, 3+2) - (1, 5) - in range
// (4) - (4-2, 4+2) - (2, 6) - in range
// (5) - (5-2, 5+2) - (3, 7) - not in range
// (6) - (6-2, 6+2) - (4, 8) - not in range

// ans = [3, 4] => count = (2)

// Time complexity - O(n)
// Space complexity - O(1)

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        
        long long int minDiff=0, maxDiff=0, val=0, start, end;
        for(int d : diff)
        {
            val+=d;
            minDiff = min(minDiff, val);
            maxDiff = max(maxDiff, val);
            
        }

        int cnt=0;
        for(int i=lower; i<=upper; i++)
        {
            start = i+minDiff;
            end = i+maxDiff;
            if(start>=lower and end<=upper)
                cnt++;
        }
        return cnt;
    }
};