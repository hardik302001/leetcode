// all perm + sort + kth

// class Solution {
// public:
    
//     vector<string>ans;
    
//     void permutate(string &l , int ind , int n){
//         if(ind==n){
//             ans.push_back(l);
//             return ;
//         }
    
//         for(int i = ind; i<n ; i++){
//             swap(l[ind], l[i]);
//             permutate(l , ind+1, n);
//             swap(l[ind], l[i]);
//         }       
//     }
    
    
    
//     string getPermutation(int n, int k) {
//         string l;
//         for(int i = 1;i<=n;i++){
//             l+=(to_string(i));
//         }
        
//         permutate(l ,0 , n);
        
//         sort(ans.begin(), ans.end());
//         return ans[k-1];
//     }
// };




/*
Time complexity: O(N! * N) +O(N! Log N!)

Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 

Reason: Result stored in a vector, we are auxiliary space taken by recursion

*/



// credits:  https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
// optimised

class Solution {
public:    
    
    string getPermutation(int n, int k) {
        int f = 1;
        for(int i = 1;i<n;i++){    // (n-1)!
            f*=i;
        }
        
        string l;                 // to store all nums
        for(int i = 1;i<=n;i++){
            l+=(to_string(i));
        }
        
        k--;   // 0 based indexing
    
        string ans;
        while(true){
            ans +=  l[k/f];
            if(ans.size()==n )  break;

            
            // necesaary to remove (k/f) position element bcz we have used it,
            // for ex:  [1 2 3 4] , we used 3
            // so our l shud be [ 1 2 4], remob=ving and making i=our search space small
            l.erase(l.begin()+k/f);
            
            //first erase , then update k and f
            
            k = k%f;            
            f = f/l.size();     // dividnig f by (n-1), then (n-2)...1
            // initially l.size() is 1 , but after removing k/f th position element l.size() is (n-1)..
            // after dividing f by l.size(), we are reducing fcatorial scope for (n-1)! to (n-2)!
            

        }
        
        return ans;
    }
};

/*
Time Complexity: O(N) * O(N) = O(N^2)
Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

Space Complexity: O(N) 
Reason: We are storing  the numbers in a data structure(here vector)
*/
