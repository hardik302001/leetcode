// bitmanipulation

/*
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        int n = nums.size();
        int maxsize = 1<<n;

        for(int subsetmask=0;subsetmask<maxsize;subsetmask++){
            vector<int> temp;
            for(int j=0;j<n;j++){
               if((subsetmask>>j)&1){
                   temp.push_back(nums[j]);
               }
            }
            sort(temp.begin(),temp.end());
            s.insert(temp);                            //to avoid repetition, bcz we need unique.. see tc [ 1,2,2 ]
       }
       
       for(auto x:s){
            ans.push_back(x);
       }
        
       return ans;      
    }
};

*/


// alterate method , ignoring the repeated ones..
class Solution {
public:
   void backtrack(int i,vector<int>& nums,int n,vector<int>curr,vector<vector<int>>&ans)
    {
        ans.push_back(curr);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i&&nums[j]==nums[j-1])continue;
            curr.push_back(nums[j]);
            backtrack(j+1,nums,n,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();
        backtrack(i,nums,n,curr,ans);
        return ans;
    }
};