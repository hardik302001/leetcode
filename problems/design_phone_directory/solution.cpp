class PhoneDirectory {
public:
            priority_queue<int>pq;
        map<int, bool>ma;
    PhoneDirectory(int maxNumbers) {

        for(int i = 0;i<maxNumbers;i++){
            pq.push(i);
            ma[i] = true;
        }
    }
    
    int get() {
        if(pq.size()){
            int topa = pq.top();
            pq.pop();
            ma[topa] = false;
            return topa;
        }else return -1;
    }
    
    bool check(int number) {
        return ma[number];
    }
    
    void release(int number) {
        if(ma[number]==false){
        pq.push(number);
        ma[number] = true;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */