// dp
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>steps(n, INT_MAX);
        steps[0] = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1; j<min(i + 1 +  nums[i], n);j++){
                steps[j] = min(steps[j] , 1 + steps[i]);
        //      for(int i = 0;i<n;i++){
        //          cout<<steps[i]<<" ";
        //      }
        //      cout<<endl;
            }
        }

        return steps[n-1];
    }
};

*/


// greedy
/*
#  Solution 2: Greedy

# The main idea is based on greedy.
# Step 1: Let's say the range of the current jump is [left, right], farthest is the farthest position that all positions in [left, right] can reach.
# Step 2: Once we reach to right, we trigger another jump with left = right + 1, right = farthest, then repeat step 1 util we reach at the end.
*/
// BFS LIKE SOLUTION
class Solution{
public:
    int jump(vector<int>&nums){
        int n = nums.size();
        int left = 0;
        int right = 0;
        int farthest = 0;
        int jump = 0;
        while( right < n-1 ) {
            for(int i = left; i<=right;i++){
                farthest = max(farthest , i + nums[i]);
            }
            left = right +  1;
            right = farthest;
            jump++;
        }
        
        return jump;

    }   
};