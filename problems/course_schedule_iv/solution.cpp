// TOPOSORT
/*
This problem is a direct application of kahn's algorithm with addition to that, we need to maintain a table which represents if two courses are prerequisites of one another.

Push all the vertices with indegree 0 to the queue.
For all such vertices, decrease their adjacent vertex's indegree by 1 since we are removing current vertex from the queue.
for table[i][j] such that i is prerequsite of j , make it true for current vertex & it's adjacent, and also if current vertex had a prerequisite, that will apply to current vertex's neighbour also for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;


# if a is prerequisite for b, then all courses that are prerequiste of a are also prereq for b.
# check from past pov
*/


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> graph(n);   
        vector<vector<bool>> table(n,vector<bool>(n,false));
        vector<int> indegree(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(auto &it :graph[cur])
            {
                table[cur][it]=true;
                for(int i=0;i<n;i++) if(table[i][cur]==true) table[i][it] = true;
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        for(int i=0;i<queries.size();i++) ans.push_back(table[queries[i][0]][queries[i][1]]);
    
        return ans;
    }
};


// bfs
/*
There can be a path between 2 nodes either directly or indirectly.
# if 'A' is prerequisite of 'B' then 'A' is also a prerequisite of all courses with 'B' as prerequisite

*/
/*
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        int p = pre.size();
        int qe = queries.size();
        vector<bool> result(qe,0);
        vector<vector<int>> adj(n);
        vector<vector<bool>> possible(n,vector<bool>(n,0));
        
        for(auto &p : pre) 
            adj[p[0]].push_back(p[1]);
       
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
            bfs(i, q, adj , possible);
        }
        
        for(int i=0;i<qe;i++)
            result[i] = possible[queries[i][0]][queries[i][1]];
        
        return result;
    }
    
    void bfs(int i , queue<int>&q, vector<vector<int>> &adj ,vector<vector<bool>> &possible) {
        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(int v : adj[course]) {
                if(!possible[i][v]){
                    possible[i][v] = 1;
                    q.push(v);
                }
            }                
        }
    }
};

*/

// floyd warshall
// O(n^3)
/*
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>  reachable(n,vector<bool>(n,0));
        for(auto &p : prerequisites) 
            reachable[p[0]][p[1]] = 1;
        vector<bool> result;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
					//if i is a direct prerequisite of j or i is a prerequisite of k which is a prerequisite of j
                }
            }
        }
        for(auto &q : queries) 
            result.push_back(reachable[q[0]][q[1]]);
        return result;
    }
};
*/