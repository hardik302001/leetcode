//same as : https://leetcode.com/problems/time-based-key-value-store/



// For every index, we store vector which has <snapshot_id, value> pair.
// During search, we do binary search in the array to find the snapshout_id <= given_snapshotId where value was written, and return that.

using namespace std;
class SnapshotArray {
    int cur = 0;
    unordered_map<int, vector<pair<int, int>>> um;

public:
    SnapshotArray(int length) {
    }
    
    void set(int key, int val) {
      um[key].push_back( {val, cur} );
    }
    
    int snap() {
        return cur++;
    }
    
    int get(int key, int id) {
        if(um.count(key)){
            int start = 0, end = um[key].size();
            while(start < end) {
                int mid = start + (end-start)/2;
                if(um[key][mid].second > id)
                    end = mid;
                else
                    start = mid + 1;
            }
            
            
            //m[key][start].first would return the first occurrence of "next" value. To get the last occurrence we want to                   //previous value hence m[key][start-1].first.
            //  if((start - 1) >= 0 and (start - 1) < m[key].size()) is to make sure we are not out of bounds.
            
            return start > 0 and start <= um[key].size() ? um[key][start-1].first : 0;
        }
        return 0;
    }
};