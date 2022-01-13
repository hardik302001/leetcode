// binary search on force!
/*



# minimise maximum, so we return do hi = mid for valid case, and return low
# if it was maximise minimum, then we will do li = mid +1 for valid case and return li - 1
#                        OR
# keep a speerate variable ans , and equate ans to the value, whenever we get valid result for answer from function

*/

//similar to : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

// Time: O(log(max(A)) * N + NlogN)
// Space: O(1)
class Solution {

public:
    int maxDistance(vector<int>& A, int m) {
        sort(begin(A), end(A));
        if (m == 2) return A.back() - A[0];
        int L = 1 , R = A.back() - A[0];
        while (L < R) {
            int M = (L + R) / 2;
            if (valid(A, M, m)){
                L = M+1;
            }
            else{
                R = M;
            }
        }
        return L-1;
    }
    
    bool valid(vector<int> &A, int M, int m) {
        int ind = 1;  //why ind==1, and m==1 , bz we have d=fixed our first ball in first basket, so we start from second position
        int prev = 0;
        for(int i = 1;i<m;i++){
            while(ind<A.size() and A[prev] + M > A[ind]){
                ind++;
            }        
            
            if(ind<A.size() and A[prev]+M<=A[ind]){   // we need ind<A.size(), bcz what if after while loo it is at last index, so when here we will access A[ind], it will give error
                prev = ind;
                ind++;
            }
            else{
                return false;
            }
            
        }
        
        return  true;
    }
    
};