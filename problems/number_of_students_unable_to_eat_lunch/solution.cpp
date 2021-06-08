//iterate second tc
//for more clarity

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sand) {
        int ans{};
		// Use deque to be able to find values in it
        deque<int> q;
        
		// Create queue
        for (int s : students) {
            q.push_back(s);
        }
        
        while (true) {
		    // If the top sandwich is not found in the students, we are stuck in an infinite loop
			// Time to break
            if (find(q.begin(), q.end(), sand[0]) == q.end()) {
                break;
            }
            
			// First student take the sandwich
            if (q.front() == sand[0]) {
                q.pop_front();
                sand.erase(sand.begin());
            }
            else {
			    // First student goes back at the end of the deck
                q.push_back(q.front());
                q.pop_front();
            }
                
        }
        
        return (int) q.size();
    }
};