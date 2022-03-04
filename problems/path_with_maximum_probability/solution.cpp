#define INF 100000
#define ld long double
    

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector< vector<pair<int , double> >>graph(n+1);
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<ld>prob(n+1, 0.00);
        priority_queue<pair< ld, int>>pq;
        pq.push({1.0,start});
        prob[start] = 1.0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto edge:graph[node]){
                if(d * edge.second>prob[edge.first]){
                    prob[edge.first] = d * edge.second;
                    pq.push({prob[edge.first] , edge.first});
                }
            }
        }
        
        return prob[end];
        
    }
};