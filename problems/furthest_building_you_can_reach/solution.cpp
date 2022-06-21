class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int> , greater<int>>pq; // min heap to keep track of number of ladders;
        
        int n = heights.size();
        for(int i = 1; i<n;i++){
            if(heights[i]<= heights[i-1]) continue;
            int dif = heights[i]-heights[i-1];
            pq.push(dif);
            if(pq.size()>ladders){
                auto top = pq.top();
                pq.pop();
                bricks-=top;
                if(bricks<0) return i-1; 
            }
        }
        
        return n-1;
    }
};