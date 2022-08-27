// idea: https://www.geeksforgeeks.org/maximum-sum-subarray-having-sum-less-than-or-equal-to-given-sum-using-set/


// upper_bound -> iterator point to first element in the range [first,last) greater than 'val'
// lower_bound -> iterator point to first element in the range [first,last) which has a value not less than ‘val’ [ equal or greater ]


// no large than k , means less than equal to k , so we use lower_bound here
// TC: O(N^3 logn )

class Solution{
public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // Precompute prefix sums for each row
        for (int row = 0; row < matrix.size(); ++row) {
            int currSum = 0;
            for (int col = 0; col < matrix[row].size(); ++col) {
                currSum += matrix[row][col];
                matrix[row][col] = currSum;
                // cout<<matrix[row][col]<<" ";
            }
            // cout<<endl;
        }
        
            
            
        int maxSum = INT_MIN;
    
        // now we fix left and right pointer for each of rectangle possible width [lcol , rcol]
        for (int lCol = 0; lCol < matrix[0].size(); ++lCol) {
            for (int rCol = lCol; rCol < matrix[0].size(); ++rCol) {
                
                // initial height
                set<int> s; // RB tree(set)
                s.insert(0);
                
                // pref sum of heights
                int rowPrefSum = 0;
                
                for (int row = 0; row < matrix.size(); ++row) {
                    int currSum = matrix[row][rCol] - (lCol == 0 ? 0 : matrix[row][lCol-1]);
                    rowPrefSum += currSum;  
                    
                    auto searchRes = s.lower_bound(rowPrefSum - k);
                    
                    if (searchRes != s.end()) {      
                        maxSum = max(maxSum, rowPrefSum - *searchRes);   // we are removing some of the sum of pref rows
                    }
                    // cout<<lCol<<" "<<rCol<<" "<<rowPrefSum<<endl;
                    s.insert(rowPrefSum);                                 // we are adding pref sum to set
                }
            }
        }
        
        return maxSum;
    }
};
