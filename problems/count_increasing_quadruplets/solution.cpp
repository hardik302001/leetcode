typedef long long int ll;

class Solution {
    vector<vector<ll>> CalculateBefore (vector<int>& arr) {
        int n = arr.size();
        
        // result[i][j] - 
        //     - How many indexes are there before "j" which are less than arr[i]
        vector<vector<ll>> result(n, vector<ll>(n));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                result[i][j] = (j > 0)? result[i][j-1] : 0; 
                if (arr[i] > arr[j]) result[i][j] ++;
            }
        }
        
        return result;
    }
    
    vector<vector<ll>> CalculateAfter  (vector<int>& arr) {
        int n = arr.size();
        
        // result[i][j] - 
        //     - How many indexes are there after "j" which are greater than arr[i]
        vector<vector<ll>> result(n, vector<ll>(n));
        
        for (int i = 0; i < n; i ++) {
            for (int j = n-1; j > i; j --) {
                result[i][j] = (j < n-1)? result[i][j+1] : 0; 
                if (arr[i] < arr[j]) result[i][j] ++;
            }
        }
        
        return result;
    }
    
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<ll>> before_smaller = CalculateBefore (nums);
        vector<vector<ll>> after_greater  = CalculateAfter  (nums);
        
        ll result = 0;
        
        for (int j = 1; j < n-2; j ++) {
            for (int k = j+1; k < n-1; k ++) {
                if (nums[j] < nums[k]) continue;
                
                result += before_smaller[k][j-1] * after_greater[j][k+1];
            }
        }
        return result;
    }
};