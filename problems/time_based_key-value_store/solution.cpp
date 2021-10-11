class TimeMap {
public:

    unordered_map<string,vector< pair<string, int> > >um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        um[key].push_back( {value, time} );
  
    }
    
    string get(string key, int time) {
        if(um.count(key)){
            int start = 0, end = um[key].size();
            while(start < end) {
                int mid = start + (end-start)/2;
                if(um[key][mid].second > time)
                    end = mid;
                else
                    start = mid + 1;
            }
            
            
            //m[key][start].first would return the first occurrence of "next" value. To get the last occurrence we want to                   //previous value hence m[key][start-1].first.
            //  if((start - 1) >= 0 and (start - 1) < m[key].size()) is to make sure we are not out of bounds.
            
            return start > 0 and start <= um[key].size() ? um[key][start-1].first : "";
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */