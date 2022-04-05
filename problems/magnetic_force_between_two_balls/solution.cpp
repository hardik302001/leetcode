// binary search on force!
// THIS QUES IS EXACTLY SAME AS : AGGRESSIVE COWS
// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559



/*

# minimise maximum, so we return do hi = mid for valid case, and return low
# if it was maximise minimum, then we will do li = mid +1 for valid case and return li - 1
#                        OR
# keep a speerate variable ans , and equate ans to the value, whenever we get valid result for answer from function

*/

//similar to : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

// Time: O(log(max(A)) * N + NlogN)
// Space: O(1)

// maximise the minimum

class Solution {

public:
    int maxDistance(vector<int>& A, int k) {
        sort(begin(A), end(A));
        if (k == 2) return A.back() - A[0];
        int L = 1 , R = A.back() - A[0];
        while (L < R) {
            int M = (L + R) / 2;
            if (valid(A, M, k)){
                L = M+1;
            }
            else{
                R = M;
            }
        }
        return L-1;
    }
    
    bool valid(vector<int> &A, int M, int k) {
        // fix first ball
        
        int prev = A[0];
        int placed = 1;
        
        for(int i = 1 ;i<A.size();i++){
            if(A[i]-prev >= M){
                placed++;
                prev = A[i];
            }
        }
                
        return placed>=k;
    }
    
};