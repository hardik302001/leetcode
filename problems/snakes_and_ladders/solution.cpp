class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int c= 0;
        int n = board.size();

        vector<bool> vis(n*n+1, false);
                
        queue<int>q;
        int start = 1;
        vis[start] = true;
        q.push(start);
        
        
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int cur = q.front();
                q.pop();
                if(cur == n*n){
                    return c;
                }
                
                for(int dice = 1;dice<=6 and cur + dice<= (n*n);dice++){
                    int next = cur + dice;
                    // finding coord of next in matrix, from top to bottom and leftf to right!
                    // as then only we will take the decison to whether continue, or it is snake/ladder and move directly
                    
                    int x = n - 1 - next/n;
                    if(next%n==0){
                        x++;
                    }
                    int y = (n-1-x)%2?  n-1-next%n+1  :  next%n - 1;
                    if(next%n==0){
                        if((n-1-x)%2){
                            y = 0;
                        }
                        else{
                            y = n-1;
                        }
                    }
                    
                    
                    // cout<<x<<" "<<y<<endl;
                    
                /*
                Always do the pruning (basically checking visited and pushing in queue ) in the while loop only, before pushing in quwue ....
                
                */
                    if(board[x][y]==-1){
                        if(!vis[next]){
                            vis[next] = true;
                            q.push(next);
                            
                        }
                    }
                    else{
                        if(!vis[board[x][y]]){
                            vis[board[x][y]] = true;
                            q.push(board[x][y]);
                        }
                    }
                    
                    
                }
            }
            
            // cout<<" ----------------------------------- "<<endl;
            c++;
        }
        
        /*
        [1,1,-1]
        [1,1,1]
        [-1,1,1]
        */
        
        /*
        
        [[-1,33,-1,-1,-1,-1,-1,-1],
        [5,-1,-1,-1,-1,49,-1,-1],
        [-1,-1,-1,31,-1,-1,54,43],
        [-1,-1,26,13,41,-1,-1,-1],
        [-1,-1,-1,-1,14,45,23,2],
        [30,33,-1,-1,-1,-1,31,-1],
        [17,49,-1,-1,-1,-1,-1,-1],
        [-1,56,12,47,-1,-1,-1,-1]]
        
        */
    
        
        
        return -1;
        
    }
};