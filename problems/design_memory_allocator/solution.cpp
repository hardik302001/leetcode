class Allocator {
public:
    vector<int>vis;
    map<int, int>m;
    Allocator(int n) {
        for(int i = 0;i<n;i++){
            vis.push_back(-1);
        }
    }
    
    int allocate(int size, int mID) {  // sliding window
        int n = vis.size();
        int i = 0;
        while(i<n){
            int newi = i+1;
            if (vis[i]==-1){
                int f = 0;
                if(i+size-1<n){
                    for(int j = i;j<i+size;j++){
                        if(vis[j]!=-1){
                            newi = j+1;
                            f = 1;
                            break;
                        }
                    }
                }else{
                    return -1;
                }
                
                if(f==0){
                    for(int j = i;j<i+size;j++){
                        vis[j] = mID;
                    }
                    m[mID]+=size;
                    return i;
                }
            }
            
            i = newi;
        }
        
        return -1;
    }
    
    int free(int mID) {
        int n = vis.size();
        for(int i = 0;i<n;i++){
            if(vis[i]==mID) vis[i] = -1;
        }
        
        int ans = m[mID];
        m[mID] = 0;
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */