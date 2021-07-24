class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar) {
        int n = times.size();
        int alpha = 0;
        vector<pair<int, int> > st(n);
        vector<pair<int, pair<int,int> > > vec;
        priority_queue<int, vector<int> , greater<int>> p;
        for(int i = 0;i<n;i++){
            p.push(i);
            alpha++;
        }
        
        int a = times[tar][0];
        int b= times[tar][1];
        for(int i = 0;i<n;i++){
            if(times[i][0]<a){
                vec.push_back(make_pair(times[i][0], make_pair(1, i)));
            }
            if(times[i][1]<=a){
                vec.push_back(make_pair(times[i][1], make_pair(-1, i)));
            }
        }
        
        sort(vec.begin(),vec.end());
        
        int sze = vec.size();
        vector<int>res(sze);
        for(int i = 0;i<sze;i++){
            if(vec[i].second.first<=0){
                st[vec[i].second.second].second = i;
            }
            else{
                st[vec[i].second.second].first = i;
            }
        }
        
        for(int i = 0;i<sze;i++){
            if(vec[i].second.first>0){
                int e = p.top();
                res[i] = e;
                p.pop();
            }
            else{
                int ind = st[vec[i].second.second].first;
                int l = res[ind];
                p.push(l);
            }
        }
        
        return p.top();
        
    }
};