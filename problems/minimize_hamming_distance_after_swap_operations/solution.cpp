//SMALLEST STRING WITH SWAPS LEETCODE, DO THAT ALSO


/*
here getting idea that ques belong to graph or dfs traversal ...
NUMBER OF COMPONENT PRESENT IN GRAPH
one component of graph where we can swap any index to any other index within component .. so minimum distance for this component is number of mismatched component |||
*/


class Solution {
public:
    
    
    vector<bool> visited;
    vector<vector<int>> graph;
    
    void dfs(int start , vector<int>& path){
        path.push_back(start);
        visited[start]= true;
        for(auto it : graph[start]){
            if(!visited[it]){
                dfs(it,path);
            }
        }
    }
    
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        graph.resize(source.size());
        visited.resize(source.size(),false);
        for(auto swap : allowedSwaps){
            graph[swap[0]].push_back(swap[1]);
            graph[swap[1]].push_back(swap[0]);
        }
        
        int ans=0;
        for(auto i=0;i<graph.size();i++)
            if(!visited[i]){
                vector<int>path;
                dfs(i , path);
                unordered_map<int , int> m;
                
                //first count in source then remove from target bcz, we are doing swaps in source array
                
                for(auto it : path){
                    m[source[it]]++;
                }
                
                for(auto it: path){
                    if(m.find(target[it]) != m.end()){
                        m[target[it]]--;
                    }
                }
                
                for(auto it : m ){
                    if(it.second > 0){
                        ans +=it.second;
                    }
                }
            }
        return ans;
    }
};