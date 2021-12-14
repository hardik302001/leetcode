// see this question first, then come here https://leetcode.com/problems/max-chunks-to-make-sorted/submissions/

// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/discuss/1353092/C%2B%2B-3-approaches-(each-commented-with-intuition)



//see pepcoding video for this question
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        if(arr.size() == 0) return 0;
        
        int n = arr.size();
        vector<int> leftMax(n+1);
        vector<int> rightMin(n+1);

        int maxTillHere  = INT_MIN; 
        for(int i=0; i<n; i++)  {
            maxTillHere = max(maxTillHere , arr[i]);
            leftMax[i] = maxTillHere;
        }
            
        leftMax[n] = leftMax[n-1];
        
        int minTillHere = INT_MAX;
        for(int j=n-1; j>=0; j--) {
            minTillHere = min(minTillHere , arr[j]);
            rightMin[j] = minTillHere;
        }
        rightMin[n] = INT_MAX;

        int cnt = 0;
        for(int i=0; i<n; i++) 
        {
            if(leftMax[i] <= rightMin[i+1]) cnt++;
        }
        return cnt;
        
    }
};



//monotonic stack solution

// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         for(int i=0;i<n;i++){
//             int largest = arr[i];
//             while (!st.empty() and st.top() > arr[i]){
//                 largest = max(largest, st.top());
//                 st.pop();
//             }
//             st.push(largest);
//         }
//         return st.size();
//     }
// };