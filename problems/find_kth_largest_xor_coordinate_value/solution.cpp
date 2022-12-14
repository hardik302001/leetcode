
 
// Time Complexity : O(NMlogK)
// idea :https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/discuss/1032010/Detailed-Explanation-or-C%2B%2B-Solution-or-Easy-Implementation

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) { 
        int i, j, n = matrix.size(), m = matrix[0].size();
        priority_queue< int, vector<int>, greater<int> >pq;
        
		// Step 1
        for(i = 0; i < n; i++)
        {
            for(j = 1; j < m; j++)
            {
                matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
            }
        }
        
		// Step 2
        for(i = 0; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];
            }
        }
        
		// Step 3
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(pq.size() < k)
                    pq.push(matrix[i][j]);
                else
                {
                   if(matrix[i][j] > pq.top())
                   {
                       pq.pop();
                       pq.push(matrix[i][j]);
                   }
                }
            }
        }
        
        return pq.top();
    }
};