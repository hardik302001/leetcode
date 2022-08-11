/*
PARALLEL COURSE 1

There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

Example 1:
Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.

Example 2:
Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.

Note:
1 <= N <= 5000
1 <= relations.length <= 5000
relations[i][0] != relations[i][1]
There are no repeated relations in the input.



Soln: https://walkccc.me/LeetCode/problems/1136/
*/


// -----------------------------------------------------------------------------

// maxTime[node] = max(maxTime[node],maxTime[parentNode]+time[node-1]); // node-1 bcz 0 based indexing used in given time array

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<long long int> adj[n+1];
        vector<long long int> indegree(n+1,0);
        vector<long long int> maxTime(n+1,0);
        for(long long int i=0;i<rel.size();i++)
        {
            adj[rel[i][0]].push_back(rel[i][1]);
            indegree[rel[i][1]]++;
        }
        queue<long long int>q;
        for(int i=1;i<=n;i++)
        {
            maxTime[i] = time[i-1];
            if(!indegree[i])
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int ss = q.size();
            for(int i=0;i<ss;i++)
            {
                int parentNode = q.front();q.pop();
                // cout<<node<<" "<<adj[node].size();
                for(long long int child : adj[parentNode])
                {
                    indegree[child]--;
                     maxTime[child] = max(maxTime[child],maxTime[parentNode]+time[child-1]);
                    if(!indegree[child])
                    {
                        q.push(child);
                    }
                }
            }
            
            
        }
        long long int ans = -1;
        for(long long int value : maxTime)
            ans = max(ans , value);
        return ans;
    }
};


