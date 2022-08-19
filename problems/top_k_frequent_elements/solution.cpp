


//similar to https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/



class Comp {
public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
              if(lhs.first<rhs.first){
                    return true;
                }
                else if(rhs.first<lhs.first){
                    return false;
                }
                else{
                    if(lhs.second<rhs.second){
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> cnt;
        for (auto& w : nums)
            ++cnt[w];
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> Q;
        for (auto it : cnt)
            Q.emplace(it.second, it.first);
        
        vector<int> res;
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};