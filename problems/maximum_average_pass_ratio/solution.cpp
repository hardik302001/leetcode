/*
The correct approach is:
Find the difference, namely the delta.
For example, even though 1/2 and 10/20 has the same ratio. However, 1/2's delta is equal to (1+1)/(2+1)-1/2, which is much greater than (10+1)/(20+1)-10/20.
Therefore, we always greedily select the one with the greatest delta.
We can acheive this using a max heap. In C++, we can use the priority queue.
*/


class cmp{
    public: 
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        double ad = (a.first+1)/(double)(a.second+1) - (a.first)/(double)a.second;
        double bd = (b.first+1)/(double)(b.second+1) - (b.first)/(double)b.second;
        return ad < bd;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double acc = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> que;
        for(vector<int> i: classes)
            que.push(make_pair(i[0],i[1]));
        while(extraStudents--){
            pair<int,int> cur = que.top(); que.pop();
            cur.first++, cur.second++;
            que.push(cur);
        }
        while(!que.empty()){
            pair<int,int> cur = que.top(); que.pop();
            acc += cur.first / (double) cur.second;
        }
        return acc / (double) classes.size();
    }
};