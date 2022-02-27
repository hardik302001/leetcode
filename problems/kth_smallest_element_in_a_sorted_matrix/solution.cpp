class Solution { // 20 ms, faster than 98.92%
public:
    int n, m;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        int left = matrix[0][0], right = matrix[m-1][n-1];
        
        while (left < right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                right = mid; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return left;
    }
    
    
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0;
        
        for (int r = 0; r < m; ++r) {
            int c = n - 1; // start with the rightmost column
            while (c >= 0 && matrix[r][c] > x) c--;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
};

