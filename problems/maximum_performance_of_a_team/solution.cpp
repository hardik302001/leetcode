// TC : O(nlogn)

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int , int>>p; 
        priority_queue< int , vector<int> , greater<int>> pq;   // min pq of speed 
        
        for(int i = 0;i<n;i++){
            p.push_back({efficiency[i] , speed[i]});
        }
        
        // reverse sort
        // decreasing efficiency
        sort(p.rbegin(), p.rend());
        long long ans = 0;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            auto [e, s] = p[i];
            
            // size can be atmax k , so we need to update
            if(pq.size()==k){
                auto topa = pq.top();
                pq.pop();
                sum-= topa;
            }
            
            // conisdering current pair
            pq.push(s);
            sum += s;
            // size scan be atmost k, so we will updte everytime
            ans = max(ans , sum*e);  // here current effciency will be minimum
        }
        return ans%1000000007;
        
    }
};