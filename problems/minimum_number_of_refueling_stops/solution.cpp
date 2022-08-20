
    
// https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/150514
// priority_queue : O(nlogn)


class Solution{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stop = 0, stationId = 0, range = startFuel;
        while (range < target) {
            while (stationId < stations.size() and stations[stationId][0] <= range) {
                pq.push(stations[stationId++][1]);
            }
            if (pq.empty()) return -1;
            range += pq.top();
            pq.pop();
            stop++;
        }
        return stop;
    }
};

