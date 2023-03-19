class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int>mp;
        for(auto x: nums){
            if(x<0){  // make positive
                x+= ((abs(x)+value-1)/value)*value;
            }
            mp[x%value]++;
        }
        int cur = 0;
        while(true){
            if(mp[cur]>0){
                mp[cur]-=1;
                mp[cur+value]+=mp[cur];
                cur+=1;
            }else{
                break;
            }
        }
        return cur;
    }
};