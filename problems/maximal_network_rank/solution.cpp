/*
Brief Explanation

Build the graph (adjacency list).
Compute network rank of all pairs of cities.
Simply compute the sum of neighbors (connected cities) of both cities.
Decrement 1 from the computed sum if the cities under consideration are connected to each other.
(Otherwise the road between those 2 cities will be double counted)
Update the maximal network rank if the network rank computed is greater than the current value.
Note:
Used unordered_set in the graph to track neighbors (connected cities) in order to speed up the look up.
(Required to check if the 2 cities under consideration are connected or not)
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        // Building the graph (adjacency list). 
        for (const auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = graph[i].size() + graph[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if (graph[j].count(i)) {
                    network_rank -= 1;
                }else{         // do nothing 
                    network_rank += 0;
                }
                
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
    
    int max(int a , int b){
        return a>b?a:b;
    }
};