class MovingAverage {
public:
    
    queue<int>q;
    int s;
    int n;
    MovingAverage(int size) {
        n = size;
        s = 0;
    }
    
    double next(int val) {
        q.push(val);
        s+=val;
        if(q.size()>n){
            int topa = q.front();
            q.pop();
            s-=topa;
        }
        
        return s/(double)(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */