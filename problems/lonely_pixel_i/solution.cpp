class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& pic) {
        int m = pic.size();
        int n = pic[0].size();
        vector<int> rows = vector<int>(m, 0);
        vector<int> cols = vector<int>(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += pic[i][j] == 'B';
                cols[j] += pic[i][j] == 'B';
            }
        }
        int lonely = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n && rows[i] > 0; j++) {
                lonely += pic[i][j] == 'B' && rows[i] == 1 && cols[j] == 1;
            }
        }
        return lonely;
    }
};
