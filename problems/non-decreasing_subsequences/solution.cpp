class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<int> sub;
       int index=0;
       int n=nums.size();
       vector<vector<int>> ans;
       solve(index,nums,sub,ans,n); 
       return ans;
    }
    
    void solve(int index,vector<int> &nums,vector<int> &sub,vector<vector<int>> &ans,int n)
    {
        if(index==n)
        {
            if(sub.size()>1)
                ans.push_back(sub);
           return ;
        }
        if( sub.size()==0 || nums[index] >= sub[sub.size()-1])
        {
            sub.push_back(nums[index]);
            solve(index+1,nums,sub,ans,n);
            sub.pop_back();
        } 
        
        // equal elements bas upar wale step ke through hi aage jayenge, else we just ignore them
        if(sub.size()==0 || sub[sub.size()-1]!=nums[index])
        {
            solve(index+1,nums,sub,ans,n);
        }
        
    }
};