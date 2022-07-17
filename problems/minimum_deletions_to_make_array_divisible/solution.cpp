class Solution {
public:
    
    int gcds(vector<int>& arr, int idx)
    {
        if (idx == arr.size() - 1) {
            return arr[idx];
        }
        int a = arr[idx];
        int b = gcds(arr, idx + 1);
        return __gcd(a, b); 
    }
 
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc = gcds(numsDivide, 0);
        int ans= 0;
        priority_queue<int, vector<int>, greater<int>>pq(nums.begin(), nums.end());
        int c= 0;
        
        
        while(pq.size()){
            int topa = pq.top();
            pq.pop();
            if(gc%topa!=0){
                c++;
            }else{
                
                return c;
            }
        }
        
        return -1;        
    }
};