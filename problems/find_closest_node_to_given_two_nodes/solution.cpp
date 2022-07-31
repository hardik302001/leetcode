// initaly i was a dumb newb. I was comparing the nodes itself, leading to WA's. 
// We need to compare distances



// TC: O(n+e)
// -------------------------------------------------------------

// 2 bfs, find distance and do brute force, minimise max 
// Intuition:Store smallest distance from node1 to all other nodes and smallest distance from node2 to all other nodes in two arrays.

/*
class Solution {
public:
    
    void func(vector<vector<int>> &graph,int node,vector<int> &dist){
        queue<int> q;
        q.push(node);
        int step=0;
        vector<bool> vis(graph.size());
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int front=q.front();
                q.pop();
                dist[front]=step;
                vis[front]=true;
                for(int x:graph[front]){
                    if(!vis[x])q.push(x);
                }
            }
            step++;
        }
        
    }
    
    int closestMeetingNode(vector<int>& v, int node1, int node2) {
        int n=v.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(v[i]==-1)continue;
            graph[i].push_back(v[i]);
        }
        vector<int> dist1(n,1e9),dist2(n,1e9);
        func(graph,node1,dist1);
        func(graph,node2,dist2);
        int dist=1e9,ans=-1;
        for(int i=0;i<n;i++){
            if(max(dist1[i],dist2[i])<dist){
                dist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
        
    }
};
*/

// ---------------------------------------------------------------------------------------

// approach 2: find distance using parent
// Used two distance arrays for storing distance of each node from the given two nodes then finding the minimum maximum distance of node that is reachable by both nodes

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int dist1[n],dist2[n];
		//also works as visited array
        for(int i=0;i<n;i++){
            dist1[i]=-1;
            dist2[i]=-1;
        }
        int count=1,temp1=node1;
        dist1[node1]=0;
		//terminating condn -> if there is no outgoing edge from that node or the node is already visited
        while(edges[temp1]!=-1&&dist1[edges[temp1]]==-1){  // for cycles
            dist1[edges[temp1]]=count++;
            temp1=edges[temp1];
        }
        count=1;
        dist2[node2]=0;
        int temp2=node2;
        while(edges[temp2]!=-1&&dist2[edges[temp2]]==-1){  // for cycles
            dist2[edges[temp2]]=count++;
            temp2=edges[temp2];
        }
        
        int mini=INT_MAX, idx=-1;
        for(int i=0;i<n;i++){
            //if either dist is -1 i.e. the node is not reachable
            if(dist1[i]!=-1&&dist2[i]!=-1&&(max(dist1[i],dist2[i])<mini)){
                mini=max(dist1[i],dist2[i]);
                idx=i;
            }
        }
        return (mini==INT_MAX)?-1:idx;
    }
};

//--------------------------------------------------------------------------------
// approach 3: use djisktra, with weight 1
