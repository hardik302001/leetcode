// also see: https://leetcode.com/problems/k-closest-points-to-origin/
// there also we have to do quickselect



//COURTESY: CODINGMINUTES..
//QUICKSELECT : KTH SMALLEST
//BUT HERE kth largest..so n-k smallest in reversed!!
//thats all we did


//other method is priority queue also..see prev code for minhesp and max heap implementation!
// quicksort

// TC : 200ms
class Solution {
public:
    int partition(vector<int>& a,int s,int e){
        int pivot = a[e];
        int i = s-1;
        for (int j = s;j<e;j++){
            if(a[j]<=pivot){
                i++;
                swap(a[i],a[j]);
            }
        }
        
        swap(a[i+1],a[e]);
        return i+1;
    }  //standard partition functio 
    
    int findKthLargest(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;
        int c = (e + 1) - k;              // kth smallest here in n-k in reversed
        while(1){
            //rather than going recursive we went for while 1 ..bcz we did not had s and e as parameters in actual function findKthLargest
            //and only thing varying was also s and e
            
            int p = partition(nums,s,e);    // p is pivot
            if(p==c){
                return nums[p];
            }
            else if(c<p){
                e = p - 1;
            }
            else{
                s = p + 1;
            }
            
            
            //rest all is standard and same
            
        }
    }
};




// ------------------------------------------------------------------

/*

// 8 ms
//Method : Using priority queue of size k  (max heap)
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};


*/


// ---------------------------------------------------------------------



/*

// 14 ms
//Method : Using priority queue of size k  (min heap)
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

*/




// -----------------------------------------------------------------



/*
// 4ms
//Method : Using priority queue of size k

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int,vector<int>>p;
        k=a.size()-k+1;
        for(int i=0;i<a.size();i++){
            if(p.size()<k){
                p.push(a[i]);
            }
            else{
                if(p.top()>a[i]){
                    p.pop();
                    p.push(a[i]);
                }
            }
        }
        return p.top();
    }
};
//Time: In worst case, O(nlogk).

*/



// -------------------------------------------------------------------------------




// both are similar

// also see: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=2
// also see: https://www.interviewbit.com/problems/maximum-sum-combinations/
//                                                  |
//                                                 \|/
/*
Approach  (Sorting, Max heap, Map) :

Instead of brute forcing through all the possible sum combinations we should find a way to limit our search space to possible candidate sum combinations.

Sort both arrays array A and array B.

Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.

Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.

Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).

Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
already present in the max heap. To check this we can use set in C++.

Go back to 4 until K times.

Time Complexity : O(NlogN) assuming C <= N


vector<int> KMaxCombinations(vector<int>& A,vector<int>& B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int>ans;
    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int> > > pq;

    // my_set is used to store the indices of
    // the  pair(i, j) we use my_set to make sure
    // the indices doe not repeat inside max heap.
    set<pair<int, int> > my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N-1, N-1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count=0; count<K; count++) {

        // tuple format (sum, (i, j)).
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if(i-1>=0)
        {
            int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap
        if(j-1>=0)
        {
        int sum = A[i] + B[j - 1];
        pair<int,int>temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end()) {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
        }
    }
    return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>temp=KMaxCombinations(A,B,C);
    return temp;
}

*/
