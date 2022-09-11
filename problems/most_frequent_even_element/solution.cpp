class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int>m;
        for(auto x: nums){
            if(x%2==0){
                m[x]++;
            }
        }
        int p = -1;
        int f = 0;
        int c = -1;
        for(auto p:m){
            if(p.second>f){
                c = p.first;
                f = p.second;
            }
        }
        
        return c;
    }
};