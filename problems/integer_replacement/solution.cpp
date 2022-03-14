// bfs

class Solution {
public:
    int integerReplacement(int n) {
        queue<long long>q;
        q.push(n);
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            set<long long>s;
            for(int i=0;i<sz;i++){
                long long x=q.front();
                q.pop();
                if(x==1)return cnt;
                if(x%2==0){
                    s.insert(x/2);
                }
                else{
                    s.insert(x-1);
                    s.insert(x+1);
                }
            }
            cnt++;
            for(auto x: s)q.push(x);
        }
        return -1;
    }
};

//also see: https://leetcode.com/problems/integer-replacement/discuss/87948/Python-O(log-n)-time-O(1)-space-with-explanation-and-proof