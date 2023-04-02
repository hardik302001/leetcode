// https://leetcode.com/problems/mice-and-cheese/discuss/3368300/Easy-C%2B%2B-Priority-Queue-Solution

class Solution {
public:
    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
       priority_queue<int>pq;
        long long int ans=0;
        for(int i=0;i<r1.size();i++){
           pq.push(r1[i]-r2[i]);
            ans+=r2[i];
        }
        while(k!=0){
          ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};