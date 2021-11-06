//Bitmapulation
//Courtesy : codencode yt single number 2
//Tc o(32*n)
//sc O(1)




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(32,0);
        
        for(auto e: nums){
            for(int i = 0;i<32;i++){
                if(e&(1<<i)){
                    freq[i]++;
                }
            }
        }
        
        int res = 0;
        for(int i = 0;i<32;i++){
            if(freq[i]%3==1){
                res = res + (1<<i);
            }
        }
        
        return res;
    }
};