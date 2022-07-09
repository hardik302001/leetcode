// class Solution
// {
//     public:
//         int solve(int cur, int pos, int target, vector<vector < int>> &stations)
//         {
//             if (pos >= target or cur>=target)
//             {
//                 return 0;
//             }

//             int ans = INT_MAX/2;
//             for (auto pair : stations)
//             {
//                 auto p =  pair[0];
//                 auto fuel = pair[1];
//                 int dis = p - pos;
//                 if (dis <= 0)
//                 {
//                     continue;	// we wont go back
//                 }
//                 else
//                 {
//                     if (cur - dis >= 0)
//                     {
//                         int taken = 1 + solve(cur + fuel - dis, p, target, stations);
//                         int not_taken = solve(fuel- dis, p, target, stations);
//                         ans = min({ans , taken , not_taken});
//                     }else{
//                         int not_taken = solve(fuel- dis, p, target, stations);
//                         ans = min(ans , not_taken);
//                     }
//                 }
//             }
            
                            
//             return ans;
//         }

//     int minRefuelStops(int target, int startFuel, vector<vector < int>> &stations)
//     {
//         return solve(startFuel, 0, target, stations);
//     }
// };

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