class Solution {
public:
    string oddString(vector<string>& v1) {
        int n = v1.size(), m = v1[0].size();
        string ans = "";
        map<vector<int>, vector<string>> m1;
        for(auto &it: v1){
            vector<int> a;
            for(int i=1; i<m; i++)          a.push_back(it[i]-it[i-1]);
            m1[a].push_back(it);
        }
        for(auto &it: m1){
            if(it.second.size()==1) {
                ans = it.second[0];
                break;
            }
        }
        return ans;
    }
};