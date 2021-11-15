//O(n**2)
//see prev soln also (lcs variation)

//can also be optimised by binary search..I have not done that..see that part in future

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] and dp[i] < dp[j] + 1){
                // cout<<arr[j]<<" "<<arr[i]<<endl;
                dp[i] = dp[j] + 1;
            }
                
    }
 
    // Return maximum value in lis[]
    for(auto i: dp){
        cout<<i<<" ";
    }
    return *max_element(dp.begin(), dp.end());
    }
};



/*
//see prev soln also in cpp
//other soln, LIS = LCS(arr, set(sorted(arr))

//time and space : O(m*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& arr1) {
        int n = arr1.size();
        vector<int> arr2;
        arr2 = arr1;
        sort(arr2.begin(),arr2.end());
        set<int>s(arr2.begin(),arr2.end());   //we need to make set, bcz of repeating eleemnts ...lcs will consider them.., leading to a NOT strictly increasing sequence.. like sample example 3 , (7,7,7,7)..it is increasing but not strictly increasing
        //thus we will only consider one occurence in sorted array,,make a set , and again make it back to vector..and find lcs 
        vector<int>arr3(s.begin(),s.end());
        return lcs(arr1, arr3);
    }
    
    
    int lcs(vector<int>arr1, vector<int>arr2){
        int n = arr1.size();
        int m = arr2.size();
        vector< vector<int> >dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(arr1[i-1]==arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

*/