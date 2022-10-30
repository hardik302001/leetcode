class Solution{
public:

    string reorganizeString(string S) {
        vector<int> cnt(26);
        int mostFreq = 0, i = 0;

        for(char c : S)
            if(++cnt[c - 'a'] > cnt[mostFreq])
                mostFreq = (c - 'a');

        if(2 * cnt[mostFreq] - 1 > S.size()) return "";

        while(cnt[mostFreq]) {
            S[i] = ('a' + mostFreq);
            i += 2;
            cnt[mostFreq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(cnt[j]) {
                if(i >= S.size()) i = 1; // now it will follow odd indexes, i = 1, 3, 5 ...
                S[i] = ('a' + j);
                cnt[j]--;
                i += 2;   // initially , this i will be continued from mostfreq charcter filling only, i = 0,2, 4 ...
            }
        }

        return S;
    }

};

// ------------------------------------------------------------------------------

// O(nlogn)

/*
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
            pq.push(pr);
        }
        
        string ans = "";
        auto p = pq.top();
        // corner case
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

*/