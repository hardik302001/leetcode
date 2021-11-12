//similar to lcs
//here longets common subarray
//O(n2)




//what if we are asked to print that common subarray

class Solution {
public:
    int findLength(vector<int>& x, vector<int>& y) {
        int n = x.size();
        int m = y.size();
        int dp[n+1][m+1];
        int res = 0;
        int mi = 0;
        int mj = 0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(res < dp[i][j]){  //update res
                        res = dp[i][j];
                        mi = i;
                        mj = j;
                    }
                }else {
                    dp[i][j]= 0;    //do not match , make it zero
                }
            }
        }
        
        int rese = res;
        vector<int>ansx,ansy;
        while(rese--){
            ansx.push_back(x[--mi]);         
        }
        rese = res;
        while(rese--){
            ansy.push_back(y[--mj]);         
        }
        
        for(auto i : ansx){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto j : ansy){
            cout<<j<<" ";
        }
        cout<<endl;

    return res;        
    }
};