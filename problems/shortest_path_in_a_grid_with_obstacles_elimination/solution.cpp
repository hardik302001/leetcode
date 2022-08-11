/*

Solution: 
	1. Since it talks about the shortest paths, we immediately think about BFS here.
	2. We use the visited array in a different way to keep storing the number of obstacles 
		that we can still remove after walking through that cell. (Basically BEST remaining K after reaching that cell)
	3. Simply traverse the BFS by storing the X, Y, currentLength and currentK remaining in the queue.
	4. If you reach the destination index, return the currentLength
	5. If you try to access an invalid cell, 
		or you hit an obstacle but have no K to spend, 
		or this index X and Y have already been accessed and with a better remaining K than yours, WE SKIP/continue.
	6. Push the adjacent indexes into the queue.

    TC: O(mn)
    SC: O(mn)

*/


class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int M = mat.size();
        int N = mat[0].size();
        queue<vector<int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        // This vector stores the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> dis(M,vector<int>(N,-1));
        
        // x, y , curdist, remaining k
        todo.push({0,0,0,k});
        
        while (!todo.empty()) {
            int curx = todo.front()[0];
            int cury = todo.front()[1];
            int curd = todo.front()[2];
            int remk = todo.front()[3];
            
            todo.pop();
            
            
            if(mat[curx][cury]== 1){
                if(remk > 0){
                    remk--;
                }
                else{
                    continue;    //you got obstacle and you dont have chance to tackle it, so stop there only(we arent adding more nodes now with this path ) 
                }
            }
            

            // If you've reached the end, great, return the currentLength!
            if(curx == (M-1) and cury == (N-1)){
                return curd;         //return current distance
            }
            
            //if you encounter obstacle, if you have chance to tackle that obstacle, then go for it, else if you have no chance then you cant tackle this obstacle, then it of no use to continue as you cant move further
            

     
            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if(dis[curx][cury] != -1  and dis[curx][cury] >= remk){
                continue;             //we wont continue further as this path is not optimised
            }
            else{
                dis[curx][cury] = remk;  //if cell is either unvisted or (if it is visted and dis[i][j] < remk, then it is good to choose this path, over the previous path that uses more k or faces more obstacles) then update dis[i][j]
            }
            
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N)){      //we dont consider that dis[i][j]==-1 , bcz we want to consider the miniumum for each of dis[i][j] as we can find a new path with lower dis[i,[j] value, so we traverse all of them again and again!
                    todo.push({newx, newy, curd + 1 ,remk});       
                }
            }      
        }
        return -1;
    }


     bool inside(int x, int y, int &M, int &N) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
        
        
};