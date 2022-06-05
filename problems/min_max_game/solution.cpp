class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        while (size(nums) != 1) {
            
            int turn(0);
            vector<int> temp;
            for (int i=0; i<size(nums); i+=2, turn++) {
                temp.push_back((turn % 2 == 1) ? max(nums[i], nums[i+1]) : min(nums[i], nums[i+1]));
            }
            nums = temp;
        }
        return nums[0];
    }
};