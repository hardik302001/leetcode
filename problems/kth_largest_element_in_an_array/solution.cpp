//for better method see previous code
//Method 2: Using priority queue of size k

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

