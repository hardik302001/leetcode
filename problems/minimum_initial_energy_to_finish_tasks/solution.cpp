// Easy Code with Comments - Sort and Borrow energy when necessary


// a[1] & b[1] are minimum energies while
// a[0] & b[0] are actual energies required.
// Sort the array in the descending order of (minimum - actual).
// (minimum - actual) is the amount of energy that remains after 
// finishing a task. So we should try to accumulate as much energy
// as possible in the beginning to complete the tasks coming up
// ahead. Hence, sort the array in descending order based on the 
// amount of energy that will be remaining.

// Example: [[1, 10], [1, 5], [1,20]] --> [[1, 20], [1, 10], [1, 5]]


class Solution {
public:
    
    static bool comparator(vector<int> &a, vector<int>&b) {
        return ((a[1]-a[0] > b[1]-b[0]));
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        int answer = 0;
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), comparator); // custom sort, see the comment above.
        int energy = 0; // assume initial energy is 0 and we will borrow whenever necessary.
        for (int i=0; i<n; i++) {
            if (energy < tasks[i][1]) { // if sufficient energy is not available,
                int borrow = tasks[i][1]-energy; // borrow some energy.
                answer += borrow;
                energy += borrow; // energy increased because of borrowing.
            }
            energy = energy - tasks[i][0]; // now spend the energy for the task.
        }
        return answer; // total borrowed energy.
    }
};