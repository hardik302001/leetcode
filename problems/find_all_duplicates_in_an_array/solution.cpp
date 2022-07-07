// similar to https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/


// also see: https://leetcode.com/problems/first-missing-positive/


// also see: https://leetcode.com/problems/find-the-duplicate-number/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int n = abs(nums[i]);
            nums[n-1] = -nums[n-1];
            if(nums[n-1] > 0) res.push_back(abs(nums[i]));
        }
        return res;
    }
};

/*
    
    Same mark by negation as a lot of people use, if you ever come across a value that is positive after negating if you know you've seen it before!
    
*/