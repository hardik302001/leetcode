

/*
Let us group the islands by changing the 1s to their index and increment the index.
All islands in a particular group have the same index. We store the index and the corresponding area in a map and keep track of the maximum area until now.
Examples:
1 0 1 -> 2 0 3
0 1 1 -> 0 3 3
1 0 1 -> 4 0 3

Now, we traverse each 0 in the grid and find its adjacent group and add up their areas.
For the 0 at (0,1), we get area=m[2]+m[3]+1=1+4+1=6
For the 0 at (1,0), we get area=m[2]+m[3]+m[4]+1=1+4+1+1=7
We add 1 to account for the converted island.

At the end, we are left with the required answer.
*/
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j]=index;
        int count = dfs(grid, i+1, j, index) + 
                    dfs(grid, i-1, j, index) + 
                    dfs(grid, i, j+1, index) + 
                    dfs(grid, i, j-1, index);
        return count+1;
    }
    
    void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
		//finding adjacent island groups
        int n=grid.size();
        if(i>0) s.insert(grid[i-1][j]);
        if(j>0) s.insert(grid[i][j-1]);
        if(i<n-1) s.insert(grid[i+1][j]);
        if(j<n-1) s.insert(grid[i][j+1]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), res=0, index=2, count;
        map<int, int> area;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    area[index]=dfs(grid, i, j, index);
                    res=max(res, area[index++]);
					//if the grid is one large island, we would find the maximum size island here
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    set<int> s;
                    findNeighbours(grid, i, j, s);
                    count=1;    //to account for the converted island
                    for(int i:s)
                        count+=area[i];       // count the number of islands in the adjacent groups
                    res=max(res, count);
                }
            }
        }
        
        return res;
    }
};