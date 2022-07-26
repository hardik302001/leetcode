// dp idea: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286754/C%2B%2BPython-O(n3)-DP-explanation-%2B-diagrams



// TC: O(N^3)
// i , j , k

class Solution {
public:
    int dp[105][105];
    int minScore(vector<int>& A, int i, int k) {
        if( k < i + 2)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int minm = INT_MAX;
        
        for(int j = i+1; j < k; j++) {  // j i smiddle index, thats why from [i+1:k-1]
            minm = min(minm, minScore(A,i,j) + minScore(A,j,k) + A[i]*A[j]*A[k]);
        }
        return dp[i][k] = minm;
    }
    int minScoreTriangulation(vector<int>& A) {
        int i = 0, k = A.size()-1;
        int n = A.size();
        //dp.resize(n+1, vector<int>(n+1, -1));
        memset(dp, -1, sizeof(dp));
        return minScore(A, i, k);
    }
};