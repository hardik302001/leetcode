class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue< int>pq;   //max heap
        int r=grid.size();
        int c=grid[0].size();

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                //grid[i][j] is center element, we explore rhombus in all directions
                
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    pq.push(grid[i][j]);
                    continue;
                }
                pq.push(grid[i][j]);
                
                for(int k=1;k<min(r,c)/2 + 1;++k){
                    
                    if(i+k < r && i-k >=0 && j+k<c && j-k>=0){
                        int temp=0;
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j-b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j-b];
                        }
                        temp -= (grid[i+k][j]+grid[i][j+k]+grid[i-k][j]+grid[i][j-k]);
                        pq.push(temp);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        set<int>s;
        while(!pq.empty()){
            int x = pq.top();
            s.insert(x);
            pq.pop();
            if(s.size()>=3){
                break;
            }
        }
        
        vector<int>ans(s.begin(),s.end());
        reverse(ans.begin(),ans.end());
        return (ans);
    }
};
        
        
    