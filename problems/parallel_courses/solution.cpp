class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> inCount(N + 1, 0);  // or indegree
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
            inCount[relation[1]]++;
        }
        int step = 0;
        int studiedCount = 0;
        vector<int> bfsQueue;
        for (int node = 1; node < N + 1; node++) {
            if (inCount[node] == 0) {
                bfsQueue.push_back(node);
            }
        }
        // start learning with BFS
        while (!bfsQueue.empty()) {
            // start new semester
            step++;
            vector<int> nextQueue;
            for (auto& node : bfsQueue) {
                studiedCount++;
                for (auto& endNode : graph[node]) {
                    inCount[endNode]--;
                    // if all prerequisite courses learned
                    if (inCount[endNode] == 0) {
                        nextQueue.push_back(endNode);
                    }
                }
            }
            bfsQueue = nextQueue;
        }

        // check if learn all courses
        return studiedCount == N ? step : -1;
    }
};