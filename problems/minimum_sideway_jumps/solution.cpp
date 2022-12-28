// greedy 
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        
        int jumps = 0;
        int lane = 2;   //Starting lane.
        
        //The algorithm is a greeedy one.
        //On seeing obstacle in the current lane
        //We need to select the next lane which have obstacle at the farthest point. 
        
        for(int i = 0; i < obstacles.size(); ){        
            if(i+1 < obstacles.size() && obstacles[i+1] == lane){ 
                
                //Obstacle, jump required.
                jumps++;
                
                //Find the farthest lane without obstacle
                int farthest = i;   // cuurent position , we need to go up/down, so check if there is obs or not
                unordered_set<int> lanes_with_obstacle;
                lanes_with_obstacle.reserve(2);
                while(farthest < obstacles.size()){
                    
                    if(obstacles[farthest] != 0)
                        lanes_with_obstacle.insert(obstacles[farthest]);
                    
                    if(lanes_with_obstacle.size() == 2)  // we consider 2 nearest lane
                        break;
                    farthest++;
                }
                
                // the third lane , that is not nearest, will be ofc farthest
                //Jump to the farthest lane
                i = farthest;
                for(int farthest_laneidx = 1; farthest_laneidx <= 3; farthest_laneidx++){
                    if(lanes_with_obstacle.find(farthest_laneidx) == lanes_with_obstacle.end())
                        lane = farthest_laneidx;                    
                }
            }else
                i++;
        }        
        
        return jumps;
    }
};





// ---------------------------------------------------------------


/*
// memo + dfs
// dp
class Solution {
public:
    int dp[500005][4];
    
    int solve( vector<int>&obstacles, int pos , int lane){
        if(pos==obstacles.size()-1) return 0;
        
        if(dp[pos][lane]!=-1) return dp[pos][lane];
        int ans;
        if(obstacles[pos+1]!=lane) ans = solve(obstacles, pos+1, lane);
        else if(obstacles[pos+1]==lane){
            int l1=0, l2=0;
            if(lane==1)
            {
                l1=2;
                l2=3;
            }
            else if(lane==2)
            {
                l1=1;
                l2=3;
            }
            else{
                l1=1;
                l2=2;
            }
            if(obstacles[pos]==l1)
                ans = 1 + solve(obstacles, pos+1, l2);
            else if(obstacles[pos]==l2)
                ans = 1 + solve(obstacles, pos+1, l1);
            else
                ans = 1 + min(solve(obstacles, pos+1, l1), solve(obstacles, pos+1, l2));
        }
        return dp[pos][lane] = ans;
        
    }
    
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        memset(dp , -1 , sizeof dp);
        return solve(obs ,0 , 2 );
    }
};
*/

// ----------------------------------------------------------------------------------


/*
// recursion
// dfs
class Solution {
public:
    int solve( vector<int>&obstacles, int pos , int lane){
        if(pos==obstacles.size()-1) return 0;
        
        if(obstacles[pos+1]!=lane)    return solve(obstacles, pos+1, lane);
        else if(obstacles[pos+1]==lane){
            int l1=0, l2=0;
            if(lane==1)
            {
                l1=2;
                l2=3;
            }
            else if(lane==2)
            {
                l1=1;
                l2=3;
            }
            else{
                l1=1;
                l2=2;
            }
            if(obstacles[pos]==l1)
                return 1 + solve(obstacles, pos+1, l2);
            else if(obstacles[pos]==l2)
                return 1 + solve(obstacles, pos+1, l1);
            else
                return 1 + min(solve(obstacles, pos+1, l1), solve(obstacles, pos+1, l2));
        }
        return 0;
        
    }
    
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        return solve(obs ,0 , 2 );
    }
};

*/
    
// ------------------------------------------------------------------------------------
    
/*
// BFS
class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        vector<vector<bool>>vis(4, vector<bool>(n, false));
        queue<pair<int, int>>q;   // lane , ind
        q.push({2, 0});
        vis[2][0] = true;

        int ans = 0;
        
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [lane, i] = q.front(); q.pop();
                if(i==n-1) return ans-n+1;   // minimum total - horizontal = minimum side jumps
                
                if(lane-1>=1 and obs[i]!=lane-1 and !vis[lane-1][i]){
                    q.push({lane-1, i});
                    vis[lane-1][i] = true;
                }
                if(lane+1<=3 and obs[i]!=lane+1 and !vis[lane+1][i]){
                    q.push({lane+1, i});
                    vis[lane+1][i] = true;
                }
                if(lane-2>=1 and obs[i]!=lane-2 and !vis[lane-2][i]){
                    q.push({lane-2, i});
                    vis[lane-2][i] = true;
                }
                if(lane+2<=3 and obs[i]!=lane+2 and !vis[lane+2][i]){
                    q.push({lane+2, i});
                    vis[lane+2][i] = true;
                }
                if(obs[i+1]!=lane and !vis[lane][i+1]){
                    q.push({lane, i+1});
                    vis[lane][i+1] = true;
                }       
            }
            ans++;
        }
    return ans;    
    }
};

*/