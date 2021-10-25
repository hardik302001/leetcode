//TREE IS CONNECTED, only 1 connnected component
// so for each node we neeed to the sizes of subtree of each child nodes, and the count of left nodes excluding the cur node...
// why?

//for each node we will have only one parent, so when we remove all the connection from that node, we will have x connected component, each for x of the child nodes, and ONE MORE component from the parent node, and that component will also be connected having size of (n - subtreesize[node])..so we have all the things, product them and find the count of maxi prod..


class Solution {
    
public:
    vector<int> siz = vector<int>(100005,0);   //subtrree size of nodes starting with index i [5, 1, 3, 1, 1] for first sample tc 
    //we need this declaration, else we will get some weird compile error..
    //or avoid making global varaibles..make local and pass it into functions
    
    vector<int> adj[100005];
    int ma = 0;
    vector<int>score;
    
    void subtreesize(int u, int fa) {
        siz[u] = 1;
        for (int &v : adj[u]) {
            subtreesize(v, u);
            siz[u] += siz[v];
        }
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        for(int i = 1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        
        subtreesize(0,-1);
        long long cnt = 0, maxi = 0;
        for(int i=0;i<n;i++){
            long long pro = 1; 
            pro = max(pro,(long long)n - siz[i]); // calculating leftover nodes excluding child nodes (parent compponent)
            //if no parent, then pro = 1, else pro = (n- subtreesize[i])
            
            for(auto node:adj[i]){
                pro = pro * siz[node]; // multiplying with size of subtree
            }
            if(pro > maxi){
                maxi = pro;
                cnt = 1;
            }
            else if(pro == maxi){
                cnt++;
            }
        }
        return cnt;

    }
};