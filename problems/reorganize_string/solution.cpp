
class compare {
public:
    bool operator() (pair<char , int> &a, pair<char , int> &b) {
        if(a.second<b.second){
            return true;
        }
        else if (a.second>b.second){
            return false;
        }else{
            return true;
        }
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<char , int>, vector<pair<char, int>>, compare >pq;
        unordered_map<char , int>m;
        int n = s.size();
        
        for(auto &it: s){
            m[it]++;
        }
        
        for(auto &pr:m ){
            // cout<<pr.first<<" "<<pr.second<<endl;
            pq.push(pr);
        }
        
        string ans = "";
        auto p = pq.top();
        // cout<<p.first <<" "<<p.second;
        if (p.second>(n+1)/2){
            return "";
        }
        
        while(ans.size()!=n){
            auto top1 = pq.top();
            ans = ans + top1.first;
            pq.pop();
            if(pq.size()){
                auto top2 = pq.top();
                ans= ans + top2.first;
                pq.pop();
                if(top2.second>1){
                    pq.push({top2.first , top2.second -1});
                }
            }
            
            if(top1.second>1){
                pq.push({top1.first , top1.second -1});
            }
            
        }
        
        return ans;
    }
};