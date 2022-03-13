// O(n)


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        map<int,int> map;
        unordered_map<int,bool> count;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == key){
                map[i] = 1;
            }
        }
        for(auto i : map){
            for(int j=i.first - k ; j<=i.first + k;j++){
                if(!count[j] && j>=0 && j<nums.size()){
                    result.push_back(j);
                    count[j]=true;
                }
            }
        }
        return result;
    }
};