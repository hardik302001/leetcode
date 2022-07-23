class NumberContainers {
public:
    unordered_map<int, set<int>>num;   // key = number, value = set of indexes    
    unordered_map<int, int>ma;         // key = index, value = number present at that index
    NumberContainers() {
    }    
    void change(int index, int number) {
        if(ma.count(index)){
            int curnum = ma[index];
            num[curnum].erase(index);
            num[number].insert(index);
            ma[index] = number;
        }else{
            ma[index] = number;
            num[number].insert(index);
    
        }
    }
    
    
    int find(int number) {
        if(num[number].size()==0){
            return -1;
        }
        return *num[number].begin();
    }
};
