
// same as counting number of non overlapping intervals
// https://leetcode.com/problems/non-overlapping-intervals/




class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1) return 1; 
        sort(points.begin(),points.end()); // sort the points in ascending order O(nlogn)
        int high = points[0][1], arrowcnt=1;
        for(int i=1;i<points.size();i++)
        {
            if(high>=points[i][0]) // check if shares common point
                // if we take maximum, then it do not gurantee that arrow will burst all ballons,
                // bcz arrow will work at a single point, not in some range
				high = min(high, points[i][1]);
            else
             {
                 arrowcnt++;
                 high = points[i][1];
             }
        }
        return arrowcnt;
    }
};