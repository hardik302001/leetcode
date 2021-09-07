
class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b){
        if(a.second > b.second){
            return true;
        }
        else if(a.second<b.second){
            return false;
        }
        else{
            if(a.first>b.first){
                return true;
            }
            else{
                return false;
            }
            
        }
    }
    string frequencySort(string s) {
        map<char,int> m;
        for(char c: s) m[c]++;
        vector<pair<char,int>> v;
        for(auto x: m) v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),cmp);
        s="";
        for(auto x: v){
            while(x.second--){
                s+=x.first;    
            }
        }
        return s;
    }
};