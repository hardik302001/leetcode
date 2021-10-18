//same as subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int tot = 0;         //max or possible, taking all elements in account
        
        for(auto& i:a) tot |= i;
        int n = a.size();
        int ans = 0;
        
        for(int i=0;i<(1<<n);i++){
            int res = 0;
            for(int j=0;j<n;j++){
                if((i>>j)&1) res |= a[j];
            }
            if(res==tot) ans++; 
        }
        return ans;
    }
};