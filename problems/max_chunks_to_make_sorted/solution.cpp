//monotonic stack approach
//increasing stack, left to right   , we know it is similar to NGE, but here we are taking the largest of the popped ones and pushing that largest to stack!

//just print stack after each itertation and you will get it!

//this is the general question
// aslo see: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/


// in this question we have 0 to n-1, so we might not need monotonic stack, mere observations can work , so see below 2 solution , prefix sum and prefix max 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            int largest = arr[i];
            while (!st.empty() and st.top() >= arr[i]){
                largest = max(largest, st.top());
                st.pop();
            }
            st.push(largest);
        }
        return st.size();
    }
};



//prefix max approach

// class Solution {
// public:
//     //[0,1,2,3,3] -> INDEX
//     //[1,0,2,3,4] -> Original Array
//     //[1,1,2,3,4] -> Prefix MAX or You Can take MAX Variable
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         int chunks=0;
//         int CMAX=0;
//         for(int i=0;i<n;i++){
//             CMAX = max(CMAX,arr[i]);
//             if(CMAX==i) chunks++;
//         }
//         return chunks;
//     }
// };


// prefix sum approach
// class Solution {
// public:
//     //[0,1,2,3,3] -> INDEX
//     //[1,0,2,3,4] -> Original Array
    
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         int chunks=0;
//         int s1 = 0;
//         int s2 = 0;
//         for(int i=0;i<n;i++){
//             s1 += i;
//             s2 += arr[i];
//             if(s1==s2) chunks++;
//         }
//         return chunks;
//     }
// };