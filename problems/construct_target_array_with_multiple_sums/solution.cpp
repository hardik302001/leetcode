// https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/2189338/C%2B%2B-oror-Simple-Code-oror-Full-Explanation

// priority queue , reverse simulation
// use pq
// For this, we need to observe that everytime a replacement will form a new largest element in target. This means the largest element in target was formed by the last replacement.



class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num : target){
            pq.push(num);
            sum+=num;
        }
        while(pq.top() != 1){
            auto top = pq.top();
            pq.pop();
            
            sum -= top;
            
            if(sum == 0 || sum >= top) return false;
            int old = top%sum;
            if(sum != 1 && old == 0) return false;

            pq.push(old);
            sum += (old);
        }
        return true;
    }
};