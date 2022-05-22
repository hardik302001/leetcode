class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ext) {
        priority_queue<int , vector<int> , greater<int>>pq;
        int n = c.size();
        for (int i = 0 ; i<n ;i++){
            pq.push(c[i]-r[i]);
        }
        int ans = 0;
        while(pq.size() and ext){
            int t = pq.top();
            pq.pop();
            if(t==0){
                ans++;
            } 
            else if (t<=ext) {
                ext -=t;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};