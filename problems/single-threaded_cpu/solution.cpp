// shortest job first
// O(nlogn)


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>v;  // id (index) -> (enqtime , processingtime )
        int n = tasks.size();
        for(int i = 0;i<n;i++){
            v.push_back({tasks[i][0] , tasks[i][1], i});
        }
        
        sort(v.begin(), v.end());   // sort on basis of enqueue time
        priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int, int>>>pq;   // min heap
        vector<int>ans;
        long time = 0;
        int i = 0;
        while(i<n or !pq.empty()){
            if (pq.empty()) {
                time = max(time, (long)v[i][0]); // nothing in the heap? try updating the current time using the processing time of the next task in array
            }
            while (i < n and time >= v[i][0]) { // push all the tasks in the array whose enqueueTime <= currentTime into the heap
                pq.push({v[i][1], v[i][2]});
                i++;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro; // handle this task and increase the current time by the processingTime
            ans.push_back(index);
        }
        
        return ans;
    }
};