/*
There are two observations we need to make.

It is independent to consider subproblems on 0, k, 2k, ..., 1, k+1, 2k+1, ... and so on.
For each subproblem it is enough to solve LIS (longest increasing(not strictly) subsequence) problem. Indeed, if we have LIS of length t, than we need to change not more than R-t elements, where R is size of our subproblem. From the other side, we can not change less number of elements, because if we changed < R- t elements it means that > t elements were unchanged and it means we found LIS of length > t. This is called estimate + example technique in math.

Complexity
It is O(n log n) for time and O(n) for space.



*/


// here we will take upper bound because , we can have equal element, so lower bound will overwrite the value equal t it, rater it should upadate the next one..
// TC: [2,2,2,2,2,1,1,4,4,3,3,3,3,3]
//     1



class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> newArr;
            for (int j = i; j < n; j += k)
                newArr.push_back(arr[j]);
            ans += newArr.size() - longestNonDecreasingSubsequence(newArr);
        }
        return ans;
    }
    
    
    int longestNonDecreasingSubsequence(const vector<int>& arr) {
        vector<int> sub;
        sub.push_back(arr[0]);
        for (int i = 1; i < arr.size(); ++i) {
            int x = arr[i];
            if (sub.back() <= x) { // Append to LIS if new element is >= last element in LIS
                sub.push_back(x);
            } else {
                int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); // Find the index of the smallest number > x
                sub[idx] = x; // Replace that number with x
            }
        }

        return sub.size();
    }
};