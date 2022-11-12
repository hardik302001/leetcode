// Dynamic prog
// 3d dp

/*
#define ll long long
class Solution {
public:
    ll dp[101][101][101];
    ll recur(int i , int j , int rem , vector<int>& robot, vector<vector<int>>& factory){
        if(i==robot.size())   return 0;
        if(j==factory.size()) return LONG_MAX/2;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        
        if(rem==0){
            if(j+1<factory.size()){
                return recur(i , j+1 , factory[j+1][1] , robot, factory);
            }else{
                return LONG_MAX/2;
            }
        }
        ll ignore;
        ll take  = abs(robot[i] - factory[j][0]) +  recur(i+1 , j , rem-1 , robot , factory);
        if(j+1<factory.size()){
            ignore = recur(i , j+1 , factory[j+1][1] , robot, factory);
        }else{
            ignore =  LONG_MAX/2;
        }
            
        return dp[i][j][rem] =  min(take , ignore);
    
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());
        memset(dp ,-1, sizeof dp);
        
        return recur(0 , 0 , factory[0][1] , robot , factory);
        
    }
};
*/

//----------------------------------------------------------------------------------------
// 2d dp
// for every robot, we go for one of the factory

class Solution {
private:
   
    long long f(int i,int j,vector<int>& robot,vector<int>& v,vector<vector<long long>>& dp) {
        if (i==robot.size()) return 0;
        if (j==v.size()) return LONG_MAX/2;
        if (dp[i][j]!=-1) return dp[i][j];
        long long take=abs(robot[i]-v[j])+f(i+1,j+1,robot,v,dp);
        long long not_take=f(i,j+1,robot,v,dp);
        return dp[i][j]=min(take,not_take);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> v;
        for (auto i:factory) {
            int x=i[0],y=i[1];
            for (int i=0;i<y;i++) {
                v.push_back(x);
            }
        }
        vector<vector<long long>> dp(robot.size()+1,vector<long long>(v.size()+1,-1));
        return f(0,0,robot,v,dp);
    }
};