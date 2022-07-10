class SmallestInfiniteSet {
public:
    
    priority_queue<int , vector<int>, greater<int>>pq;
    unordered_map<int, int>m;
    SmallestInfiniteSet() {
        for(int i = 1;i<=10000;i++){
            pq.push(i);
            m[i]++;
        }
    }
    
    int popSmallest() {
        int topa = pq.top();
        pq.pop();
        m[topa] = 0;
        return topa;
    }
    
    void addBack(int num) {
        if(m[num]==0){
            pq.push(num);
            m[num]++;
        }
    }
};


// ----------------------------------------------------------------------

// similar set solution
/*
class SmallestInfiniteSet {
public:
    
    set<int>s;
    vector<int>vis = vector<int>(1011, 0);   // if it exist
    SmallestInfiniteSet() {
        for(int i = 1;i<=1010;i++){
            s.insert(i);
            vis[i] = 1;
        }
    }
    
    int popSmallest() {
        auto topa = *s.begin();
        s.erase(topa);
        vis[topa] = 0;
        return topa;
    }
    
    void addBack(int num) {
        if(vis[num]==0){
            s.insert(num);
        }
    }
};

*/