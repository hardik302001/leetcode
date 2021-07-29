class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        // Declare Array of maximum given constraint size to
        // store all the overlapping intervals at any time.
        // Initially no intervals overlap so initialised by 0.
        vector<int> overlap_intervals(1002, 0);
        
        // For every index in start time 
        // increment the index in array by 1
        for (int i : startTime) 
            overlap_intervals[i] += 1;
        
        // Since the intervals also contains the ending points so
        // decrement will work at index i+1.
        for (int i : endTime) 
            overlap_intervals[i + 1] -= 1;
        
        // Find the overlaps by using prefix sum technique
        for (int i = 0; i < 1001; i++) 
            overlap_intervals[i+1] += overlap_intervals[i];
        
        // return the overlaps at the given query time.
        return overlap_intervals[queryTime];
    }
};