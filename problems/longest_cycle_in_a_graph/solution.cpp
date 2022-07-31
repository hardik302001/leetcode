/*
Time Complexity : O(n)
Space Complexity : O(n)
*/
// https://leetcode.com/problems/longest-cycle-in-a-graph/discuss/2357750/Simple-Traversal-or-C%2B%2B
// this thing works because, there is atmost one outgoing edge, 

class Solution {
public:
    int maxLength = -1;
    void getcycle(vector<int> &edges,int si,vector<bool>& visit,int size,vector<int>& store){
        if(si == -1)return ;
        if(visit[si]){
            int count = -1;
            for(int i =0;i<store.size();i++){
                if(store[i]==si){
                    count = i;
                    break;
                } }
            
            if(count==-1)return;
            maxLength = max(maxLength,size-count);  // size-count gives the proper size of cycle
            return ;
        }
        
        visit[si] = true;
        store.push_back(si);
        getcycle(edges,edges[si],visit,size+1,store);
        
        return ;
        
    }
    
    
    
    int longestCycle(vector<int>& edges) {
        
        vector<bool> visit(edges.size(),0);
        for(int i =0;i<edges.size();i++){
            
            if(visit[i])continue;
            vector<int> store;
            getcycle(edges,i,visit,0,store);
     
        }
        
        return maxLength;
        
    }
};