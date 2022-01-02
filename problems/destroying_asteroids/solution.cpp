class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        vector<int>nums(ast);
        sort(nums.begin(), nums.end());
        long long mas = mass;
        for(int i =0. ;i < ast.size() ; i++){
            if(nums[i]<=mas){
                mas += nums[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};