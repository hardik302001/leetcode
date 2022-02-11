
// Another version of C++ Stack | Easy to understand | No need of pairs
// O(n)

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if (s.empty()) return 0;
        int minCost = 0;
        stack<int> stk; // stack to maintain indices parsed till now
        
        for (int i = 0; i < s.length(); ++i ) {
            if (!stk.empty() && s[stk.top()] == s[i]) {
                if (cost[stk.top()] <= cost[i]) {
                    minCost += cost[stk.top()];
                    stk.pop();
                    stk.push(i);   
                } else {
                    minCost += cost[i];
                }
            } else {
                stk.push(i);
            }
        }
        return minCost;
    }
};

// priority_queue  : Nlogn
/*
class Solution {
public:
    int minCost(string col, vector<int>& t) {
        col = "#" + col + '#';
        t.push_back(0);
        priority_queue<int>pq;  // max heap
        
        int ans = 0;
        int n = col.size();
        int cur = 0;
        for(int i = 1;i<n;i++){
            if (col[i]==col[i-1]){
                pq.push(t[i-1]);
                cur = cur + t[i-1];
            }
            else{
                if(pq.size()<=1){
                    cur = 0;
                }else{
                    int topa = pq.top();
                    cur = cur - topa;
                }
                ans = ans + cur;
                cur = 0;
                while(!pq.empty()){
                    pq.pop();
                }
                pq.push(t[i-1]);
                cur = cur + t[i-1];
            }
            // cout<<cur<<" "<<ans<<endl;
        }
        
        
        return ans;
    }
};
*/