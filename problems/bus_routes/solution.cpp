class Solution {
public:
      //to find out whether bus stops has any element common or not 
    bool connected(vector<int> &a,vector<int> &b){
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]) return true;
            else if(a[i]<b[j]) i++;
            else j++;
        }
        return false;
    }
    
    //for finding if this stop is includes in route or not
    bool present(vector<int> &nums,int s){
        // return binary_search(nums.begin(), nums.end(), s);

        int l = 0;
        int h = nums.size();
        if(nums[0]==s or nums[h-1]==s) return true;
        
        while(l<h){
            int m = l + (h-l)/2;
            if(nums[m]==s){
                return true;
            }
            
            if(nums[m]>s){
                h = m;
            }else{
                l = m+1;
            }
        }
        return false;
        
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> m;
        int n=routes.size();
        if(source==target) return 0;
        for(int i=0;i<n;i++){
            sort(routes[i].begin(),routes[i].end()); 
        }
        //making a graph of bus stops if they have an stop in common
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(connected(routes[i],routes[j])){
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
        //applying BFS on BUS STOPS
        queue<int> q;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(present(routes[i],source)){
                vis[i]=1;
                q.push(i); 
            }
        }
        int ans=1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
               int cur=q.front();q.pop();
                if(present(routes[cur],target)){
                    return ans;
                }
                for(auto x:m[cur]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};