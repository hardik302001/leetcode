/*
2 difference from nge-i

1. n-1   --->   2*n-1
2. check while updating value of nge[i], it shud be less than n
3. i = i%n
*/


//monotonic stack
//similar to nge1



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; 
        int n = nums.size();
        vector<int> res(n, -1);
      
        for(int i = 0; i < n * 2; i++) {
            int idx = i % n;
            while(!s.empty() && nums[s.top()] < nums[idx]) {
                res[s.top()] = nums[idx];
                s.pop();
            }            
            s.push(idx); 
        }
        
        return res; 
    }
    
};