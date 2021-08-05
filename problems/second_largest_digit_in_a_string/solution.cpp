class Solution {
public:
    int secondHighest(string s) {
        set<int>p;
        for(auto i:s){
            if('0'<=i and i<='9'){
                p.insert(i-'0');
            }
        }
        vector<int>v(p.begin(),p.end());
        if((v.size())>=2){
            return v[v.size()-2];
        }
    return -1;
    }
    
};