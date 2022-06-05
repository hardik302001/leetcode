class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        
        unordered_map<int,int> hm;     //****store index of element
        for(int i =0;i<nums.size();i++){
            hm[nums[i]] = i;
        }
        
        for(int i =0;i<op.size();i++){
            int a  = op[i][0];
            int b = op[i][1];    
            nums[hm[a]] = b;
            hm[b] = hm[a];  //**also store the changed element in hashmap
        }
        
        return nums;
        
    }
};