class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int between = arr.size()-2+1;
        if(arr[0]>arr.back()) reverse(arr.begin(), arr.end());
        int dif = arr.back() - arr[0];
        int per = dif/(between+1);
        
        int beg = arr[0];
        for(int i = 1;i<n;i++){
            beg = beg + per;
            int cur = beg;
            if(arr[i]!=beg) break;
        }
        
        
        return beg;
    }
};