// greedy
// O(n)
// refer : https://leetcode.com/problems/task-scheduler/discuss/760569/C%2B%2B-Greedy-O(n)-time-O(1)-space-with-explanation-in-5-lines.


class Solution {
public:
    int cnt[26], maxcnt = 0, e = 0;
    int leastInterval(vector<char>& tasks, int n) {
        for (char c : tasks) cnt[c-'A']++;
        for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);
        for (int i = 0; i < 26; i++) 
            if (cnt[i] == maxcnt) e++;  
        
        return max(int(tasks.size()), (maxcnt-1)*(n+1) + e);
    }
};

// why we need e?
// 1. bcz we dont need cooldown during lasy cycle.
// 2. bcz at end only , max freq process will be only left , so we need to only consider them.

// max of task.size , ans -> bcz see scond tc




//----------------------------------------------------------------------------




/*

// priority queue
// O(nlgn)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n + 1;   // current(1) + n
        
        while (!pq.empty()) {
            int time = 0;
            vector<int>tmp;  // to store count of only current cycle
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    int cnt = pq.top();
                    pq.pop();
                    tmp.push_back(cnt);
                    time++;
                }else{
                    break;
                }
            }
            
            // if we do the pushing work at same time, then we wont be able to know what is particular with a cycle..
            // try doing first sample tc , putting th epush part in above loop
            // the priority queue will not get empy, bcz we are eventually pushing again
            
            for(int i = 0;i<tmp.size();i++){
                if(tmp[i]-1>0) {
                    pq.push(tmp[i]-1);
                }
            }
            
            // if pq is empty, it means we only need to consider the steps we did in last cycle..
            // if its not empty , it means we completed a cycle...
            // see tc 1: we pop A and B and for third step we use 1 idle time(bcz pq is not empty), so total was 3 unit of time
            // we again pop A and B and 1 idle time(bcz pq is not empty) : 3
            // we again pop A and B , but now pq is empty , so no need for idle time 
            // bcz we wont have anyone to clash..
            
            
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};

*/