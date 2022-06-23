// SEE  SOLUTION GIVEN IN SOLUTION SECTION ALSO, FOR THE PRIORITY QUEUE code!


// Approach:
// Sort courses by the end date, this way, when we're iterating through the courses, we can switch out any previous course with the current one without worrying about end date.

// Next, we iterate through each course, if we have enough days, we'll add it to our priority queue. If we don't have enough days, then we can either
// 2.1 ignore this course OR
// 2.2 We can replace this course with the longest course we added earlier.



class Solution {
public:
    
      static bool comparator(vector<int>& v1, vector<int>& v2) {
          return v1[1] < v2[1];
      } 
    
    
    /** Main Function ***/
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(), comparator);
        
        // Priority Queue by default sorted in ascending order
        priority_queue<int> q;
        
        int sum = 0;
        for (auto& c : courses)
        {
            int t = c[0]; //Course time
            int d = c[1]; //Max day before which course has to be completed
            
            q.push(t);
            sum += t;
            
            while (sum > d)          //sum agar jyda ho gya toh pop kr rhe h..ofc popped will be less than / equal to the curr added course time
            {
                sum -= q.top(); //This can be some other long course
                q.pop();
            }

        }
        return q.size();
    }
};