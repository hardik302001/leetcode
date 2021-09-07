//similar to https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/




class Comp {
public:
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs){
              if(lhs.first<rhs.first){
                    return true;
                }
                else if(rhs.first<lhs.first){
                    return false;
                }
                else{
                    if(lhs.second>rhs.second){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
        }
};




class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words)
            ++cnt[w];
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> Q;
        for (auto it : cnt)
            Q.emplace(it.second, it.first);
        
        vector<string> res;
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};
