// we need to do pruning, else we will get tle
// see below code
// also see JUMP GAME 7
// we are also getting same problem there


// tc , sc = O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)
        return 0;
        
        unordered_map<int, vector<int> >m;
        for(int i = 0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        
        vector<bool>vis(n,false);
        queue<int> q;
        q.push(0);
        int jump = 0;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int cur = q.front();
                vis[cur] = true;
                q.pop();
                
                if(cur==(n-1)){
                    return jump;
                }
                
                if(cur-1>=0 and !vis[cur-1]){
                    q.push(cur - 1);
                }
                if(cur+1<n and !vis[cur+1]){
                    q.push(cur +1);
                }
                for(auto it: m[arr[cur]]){
                    if((it!= (cur +1) or it!= (cur-1)) or (it!=cur) and !vis[it]){
                        q.push(it);
                    } 
                }
                
                m[arr[cur]] = {};          // pruning! 
                
                //as even after marking them visited we are again checking if that value is possible or not( even though its unvisited)
                // so that redundant, same problem arises in JUMP GAME 7, also see that 
                // this line do all the magic, after using all occurrence of cur, we mark it visited and make its all occurrence as NULL, thus make the m[arr[cur]] as empty vector! , els eyou get TLE!
            }
            
            jump++;
        }
        
        
        return jump;
    }

};