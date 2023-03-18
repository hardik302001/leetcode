class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        long long sum = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // put all the values into min heap with their corresponding indexes into the min heap
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        
        // create a visited array that is initially unvisited
        vector<int> vis(nums.size(),-1);
        
        // till my min heap is not empty
        while(!pq.empty())
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            // if curr value idx in not visited before
            if(vis[idx] == -1)
            {
                // add it and mark this visited
                sum += val;
                vis[idx] = 1;
                
                // left adjacent
                if(idx-1 >= 0)
                {
                    vis[idx-1] = 1;
                }
                
                // right adjacent
                if(idx+1 < nums.size())
                {
                    vis[idx+1] = 1;
                }
            }
        }
        
        return sum;
    }
};
