class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ma = 0;
        for(auto i: accounts){
            int s = 0;
            for(auto j :i){
                s = s + j;
            }
            ma = max(ma,s);
        }
        
        
        return ma;
    }
};