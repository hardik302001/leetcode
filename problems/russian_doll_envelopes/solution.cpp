// lis
// O(n^2) dp
// TLE

/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if (envelopes.size()==0) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i]  = max(dp[i] , dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

*/

// -----------------------------------------------------------------------


// sort inc on width, if width equal , dec on height
// also implement it using nlogn lis
// link : https://leetcode.com/problems/russian-doll-envelopes/discuss/2071477/Best-Explanation-with-Pictures

class Solution {
public:
    int lengthOfLIS(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0][1]);
        for(int i = 1;i<n;i++){
            if(arr[i][1]>temp.back()){
                temp.push_back(arr[i][1]);
            }else{
                int idx = lower_bound(temp.begin(), temp.end(), arr[i][1]) - temp.begin(); // idx will always be less than / = to current temp size
                temp[idx] = arr[i][1];
            }
        }
    
        return temp.size();
    }
    
    
    bool static comp(vector<int>&a, vector<int>&b){
        if(a[0] < b[0]) return true;
        else if(a[0]==b[0]){
            if(a[1]>b[1]) return true;
            else          return false;
        }else{
            return false;
        }
    }
    
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);  
        
        int ans = lengthOfLIS(envelopes);
        return ans;
    }
};