class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        int start = a[0][0];
        int end = a[n-1][n-1];
        int ans;
        while(start < end) {
            int cnt = 0,j;
            int mid = (start+end)/2;
            for (int row = 0; row<n; row++) {
                 j = n-1;
                while(j >= 0 and a[row][j] > mid) {
                    j--;
                }
                
                cnt += (j+1);
            }
            
            if (cnt < k) {
               // ans = mid;
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};