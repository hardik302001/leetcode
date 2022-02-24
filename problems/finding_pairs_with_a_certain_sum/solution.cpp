class FindSumPairs {
public:
    unordered_map<int , int>m,n;
    vector<int>a, b;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for(auto i: a){
            m[i]++;
        }
        for(auto i:b){
            n[i]++;
        }
        
    }
    
    void add(int index, int val) {
        n[b[index]]--;
        b[index] += val;
        n[b[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(auto it: m){
            if(n.count(tot - it.first)){
                c+= it.second*n[tot-it.first];
            }
        }
        return c;
    }
};
