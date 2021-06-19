class Solution {
public:
    int thirdMax(vector<int>& nums) {

    set<int>s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    vector<int>v;
    
    for(auto i:s){
        v.push_back(i);
    }
    
    int n=v.size();
    if(v.size()>=3){
        return v[n-3];
    }
    return v[n-1];
}
    
};