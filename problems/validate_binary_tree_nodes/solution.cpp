// edge shud be n-1
// only one root
// indegree shud be 1 for every node, except root
// only one connected component

class Solution {
public:
    
    bool dfs(int src , int par, vector<int>&vis, vector<int>adj[]){     
        vis[src] = 1;
        for(auto nei: adj[src]){
            if(!vis[nei]){
			    if(dfs(nei , src, vis, adj)==true){
				    return true;                // cycle exists
			    }		
		    }else if(nei!=par){
			    return true;
		    }
	    }
	    return false;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int>adj[n];
        vector<int>indeg(n, 0);
        int edge = 0;
        for(int i = 0;i<n;i++){
            if(l[i]!=-1){
                indeg[l[i]]++;
                adj[i].push_back(l[i]);
                edge++;
            }
            if(r[i]!=-1){
                indeg[r[i]]++;
                adj[i].push_back(r[i]);
                edge++;
            }
        }
        int root = 0;
        int rn = -1;               // root of tree
        for(int i = 0;i<n;i++){
            if(indeg[i]==0){
                rn = i;
                root++;
            }else if(indeg[i]>1){
                return false;
            }
        }
        
        if(edge!=n-1 and root!=1) return false;
        vector<int>vis(n , 0);
        
        // so after this dfs, every node shud be visited, bcz only one cc allowed
        return !dfs(rn , -1, vis , adj) and !count(vis.begin(), vis.end(), 0);
        //            cycle                    only one connected component
        
        
    }
};