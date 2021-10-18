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