//bfs

class Solution {
public:
    
    bool bfs(vector<int>& arr, vector<bool>& visited, queue<int>q) {
        
        while(!q.empty()){
            
            int t= q.front(); 
            q.pop();
            if(arr[t]==0){
                return true;
            }
            if((t+arr[t])>=0 and (t+arr[t])<arr.size() and !visited[(t+arr[t])]){
                q.push(t + arr[t]);
                visited[(t+arr[t])] = true;
            }
            if((t-arr[t])>=0 and (t-arr[t])<arr.size() and !visited[(t-arr[t])]){
                q.push(t - arr[t]);
                visited[(t-arr[t])] = true;
            }
                
        }
        
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        return bfs(arr, visited, q);
    }
};
