// FIRST THING TO NOTE IS THAN UNION FIND DONT WORK HERE!
//WHY?? BCZ SEE BELOW LINK

// https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/1623585/This-is-why-Union-Find-doesn't-work-for-this-problem-with-diagram




class Solution {
public:
    int dfs(int i, vector<vector<int>> &graph, unordered_set<int> &detonated) {
        detonated.insert(i);
        for (int j : graph[i])
            if(!detonated.count(j))
                dfs(j, graph, detonated);
        return detonated.size();
    }
    
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        int n = bombs.size();
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j){
                long long x0 = bombs[i][0], y0 = bombs[i][1], r0 = (long long)bombs[i][2] * bombs[i][2];
                long long x1 = bombs[j][0], y1 = bombs[j][1], r1 = (long long)bombs[j][2] * bombs[j][2];
                if ((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) <= r0)
                    graph[i].push_back(j);
                if ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) <= r1)
                    graph[j].push_back(i);
                
            }
        }
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> detonated;
            res = max(dfs(i, graph, detonated), res);
        }
        return res;
    }
};