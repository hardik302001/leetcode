// keep track of end points
// We sort the intervals. Then, we iterate through intervals and put the right value into a min heap.
// Every time the value on top of the heap is greater or equal the left value of the next interval, we need a new group.


// exactly same as MEETING ROOMS 2, LC 253.
// Just change it interval overlapping condition, open bracket for interval end, 
// but it is closed in start and end both in this question
// https://zhuhan0.blogspot.com/2017/03/leetcode-253-meeting-rooms-ii.html

/*

class Solution {
public:
    int minGroups(vector<vector<int>>& ints) {
        sort(begin(ints), end(ints));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : ints) {
            if (!pq.empty() && pq.top() < i[0])   pq.pop();    // overlap , so pop
            pq.push(i[1]);                                      // if group exists, then it will be updated end, as we have popped previous end,
            // if group do not exist, it will be new end of this group
        }
        return pq.size();
    }
};


*/


// ----------------------------------------------------------------------------------------------------------------

// same idea : line sweep

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int N = intervals.size();

        int line[1000005] = {};
        int maxEle = -1;

        for(auto &e : intervals) {
            int start = e[0], end = e[1];
            line[start] += 1;
            line[end + 1] -= 1; // end +1 , bcz if we have starta nd end at same position, then we have to consider it, but during pref sum calculation it will become 0, no contribution, so we do end+1
        }

        for(int i = 1; i < 1000001; i++) {
            line[i] += line[i - 1];
            maxEle = max(maxEle, line[i]);
        }

        return maxEle;
    }
};