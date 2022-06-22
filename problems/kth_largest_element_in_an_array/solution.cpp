//also see: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/


//COURTESY: CODINGMINUTES..
//QUICKSELECT :KTH SMALLEST
//BUT HERE kth largest..so n-k smallest in reversed!!
//thats all we did


//other method is priority queue also..see prev code for minhesp and max heap implementation!


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
        int c = (e + 1) - k;              //kth smallest here in n-k in reversed
        while(1){
            //rather than going recursive we went for while 1 ..bcz we did not had s and e as parameters in actual function findKthLargest
            
            //and only thing varying was also s and e
            
            int p = partition(nums,s,e);
            cout<<p<<endl;
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

//Time: In worst case, O(nlogk).
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

//Time: In worst case, O(nlogk).
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