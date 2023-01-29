class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        vector<int> candidates;
        for (int i = 0; i < n-1; i++)
        {
            candidates.push_back(weights[i] + weights[i+1]);
        }
        sort(candidates.begin(), candidates.end());
        long long mins = 0, maxs = 0;
        for (int i = 0; i < k-1; i++)
        {
            mins += candidates[i];
            maxs += candidates[n-2-i];
        }
        return maxs - mins;
    }
};

/*
let suppose k=3 and for max we split at x and y
    for min we split at z and w , 
    
    score = a0 + ax + ax+1 + ay + ay+1 + an
    score = a0 + az + az+1 + aw + aw+1 + an
    
    max - min = (ax + ax+1 + ay + ay+1) - ( az + az+1 + aw + aw+1)
    so , we have to maximise & minimise adjacent sum of (k-1) pairs
    
*/

