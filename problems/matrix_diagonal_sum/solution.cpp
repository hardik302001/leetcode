class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mid = mat[n/2][n/2];
        int s = 0;
        for(int i = 0;i<n;i++){
            s = s + mat[i][i] + mat[i][n-1-i];
        }
        
        if(n%2){
            s = s - mid;
        }
        
        return s;
    }
};