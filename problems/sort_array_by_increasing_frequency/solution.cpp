class Solution {
public:

static bool comp(pair<int,int>&a, pair<int,int>&b)
{
    if(a.first < b.first){
        
        return true;
    }
    
    if(a.first == b.first){
        
        if(a.second > b.second){
            
            return true;
        }
    }
   return false;
}
vector<int> frequencySort(vector<int>& nums) {
    
    map<int,int> m;
    
    for(int i=0; i<nums.size( ); i++){
        
        m[nums[i]]++;
    }
     sort(nums.begin(), nums.end(), [&](int a, int b) { 
            return m[a] < m[b] || (m[a] == m[b] && a > b); 
        });
    return nums;
    
    
}
};