// approach 1 : in did binary search on answer, it gave TLE. 

//- ----------------------------------------------------------------------------



// sliding window maximum + sliding window for sum

class Solution {
public:
    int maximumRobots(vector<int>& chargeTime, vector<int>& runningCost, long long budget) {
        int n = chargeTime.size();
        deque<int>dq;
        int l = 0;
        long long int s = 0;
        int ans = 0;
        
        for(int r = 0;r<n;r++){
            while (!dq.empty() && chargeTime[dq.back()] < chargeTime[r])  dq.pop_back();
            
            dq.push_back(r);
            s+=runningCost[r];
 
            while(!dq.empty() and chargeTime[dq.front()] + s*(r-l+1)>budget){
                s-=runningCost[l];
                if(!dq.empty() and dq.front()<=l) dq.pop_front();
                l++;   
            }
            ans = max(ans , r-l+1);
        }
 
        return ans;
    }
};