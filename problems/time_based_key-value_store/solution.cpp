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
            // we need upper bound
            int start = 0, end = um[key].size();
            while(start < end) {
                int mid = start + (end-start)/2;
                
                if(um[key][mid].second <= time)   // cause we need upper bound
                    start = mid+1;
                else
                    end = mid;
            }
            
            
            //m[key][start].first would return the first occurrence of "next" value. To get the last occurrence we want to                   
            //previous value hence m[key][start-1].first.
            //  if((start - 1) >= 0 and (start - 1) < m[key].size()) is to make sure we are not out of bounds.
            
            return (start> 0) ? um[key][start-1].first : "";
        }
        return "";
    }
};
