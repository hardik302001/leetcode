// binary search


// Idea:
// In each iteration, we check if the current number can possibly be the kth smallest, which means that it has at least k smaller numbers in the table.
// If we have more than k smaller numbers, we continue searching in the smaller numbers - hi = mid.
// If we don't have k numbers yet, we continue searching in the higher number - lo = mid + 1.

// How do count the smaller numbers?
// In the function kSmaller we start counting.
// We loop through the rows of the table.
// Each row looks like this: [1 * i, 2 * i, 3 * i, ..., n * i].
// If the last number in the row is larger than num, then the number of smaller numbers is num/i. Otherwise, the whole row is smaller = n.
// So we add to c the minimum between the two.

// Time Complexity: O(m * log(nm)) - we do binary search on nm numbers = log(nm), and for each search we call kSmaller which is m.
// Space Complexity: O(1)

class Solution {
public:
    bool kSmaller(int n, int m, int num, int k) {      
        int c = 0;
        for (int i = 1; i <= m; i++)
            c += min(n, num/i);           //see yt video to understand this lne
        // cout<<num << " "<<c<<endl;
        return c >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m*n, mid, res;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (kSmaller(n, m, mid, k)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};