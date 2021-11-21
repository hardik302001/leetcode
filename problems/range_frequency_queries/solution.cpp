class RangeFreqQuery {
public:
    
    vector<int>l;
    vector<int> freq;
    unordered_map< int, vector<int> > store;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i=0; i<n; ++i)
        store[arr[i]].push_back(i); //starting index from 1
        
    }
    
    int query(int left, int right, int element) {
            int a = lower_bound(store[element].begin(),
                        store[element].end(),
                        left)
            - store[element].begin();
 
    // Find the position of last occurrence of element
    int b = upper_bound(store[element].begin(),
                        store[element].end(),
                        right)
            - store[element].begin();
    // cout<<a<<" "<<b<<endl; 
    return b-a;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */