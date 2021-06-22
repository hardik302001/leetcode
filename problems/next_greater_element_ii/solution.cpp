/*
2 difference from nge-i

1. n-1   --->   2*n-1
2. check while updating value of nge[i], it shud be less than n
3. i = i%n
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        vector<int>ans(n,-1);

        for(int i = 2*n-1;i>=0;i--){
            while(!s.empty() and s.top()<=nums[i%n]){
                s.pop();
            }   
            
            if(i<n){                    //nge is of size n, so all value putting work will be done only when i is less than n
                if(!s.empty()){          //now code is totally same as nge-i
                    ans[i] = s.top();
                }
                else{
                    ans[i] = -1;
                }
            }
            
            s.push(nums[i%n]);
            
        }
        

        return ans;
    }
};