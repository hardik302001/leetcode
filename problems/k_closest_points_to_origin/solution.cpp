// also see: binary/ quickselect search solution


// min heap
// tc : O(n + klogn)  // we consider only k elements
/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};
*/


// ---------------------------------------------------------------------------------
// TC: O(NlogK)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        vector<vector<int>> ans;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            pq.push(points[i]);
            if(pq.size()>K){
                pq.pop();
            }

        }
        
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {    // max heap
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};