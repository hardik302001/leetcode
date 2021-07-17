class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        pref.push_back(0);
        int s = 0;
        for(auto it: nums){
            s = s + it;
            pref.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right + 1]-pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */