
// fact that we only have positive keys, we can do it


class MyHashMap {
public:
    int hash[1000010];
    
    MyHashMap() {
        memset(hash, -1, sizeof hash);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};