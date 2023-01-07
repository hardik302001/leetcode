class DataStream {
public:
    int c;
    int o = 0;
    int vv , kk;
    DataStream(int value, int k) {
        c = 0;
        kk = k;
        vv = value;
    }
    
    bool consec(int num) {
        if(num==vv) c++;
        else c = 0;
        
        return c>=kk;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */