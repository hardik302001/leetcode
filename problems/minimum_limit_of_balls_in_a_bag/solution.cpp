//  count steps to get maximum "m"...

class Solution {
public:
    long long  minimumSize(vector<int>& nums, long long maxop) {
        sort(nums.begin(), nums.end());
        long long l = 1;
        long long r = *max_element(nums.begin(), nums.end());
        while(l<r){
            long long m = l + (r-l)/2;
            if(check(nums ,maxop , m )){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
    
    bool check(vector<int>& nums, long long maxop , long long m){
        int steps = 0;
        for(auto i: nums){
            if(i>m) steps += (i+m-1)/m - 1;
        }
        
        return steps<=maxop;
    }
};
    




//TLE , bcz i m changing vector every time to see if i can get $$$ maximum "m" $$$ in maxop steps.
// i was finding maximum...
/*
class Solution {
public:
    long long  minimumSize(vector<int>& nums, long long maxop) {
        sort(nums.begin(), nums.end());
        long long l = 1;
        long long r = *max_element(nums.begin(), nums.end());
        while(l<r){
            long long m = l + (r-l)/2;
            if(check(nums ,maxop , m )){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
    
    bool check(vector<int>& nums, long long maxop , long long m){
        priority_queue<long long>pq(nums.begin(), nums.end());
        while(maxop--){
            long long top = pq.top();
            pq.pop();
            if(top<=m){
                continue;
            }else{
                pq.push(m);
                pq.push(top- m);
            }
        }
        
        
        long long maxi = 0;
        while(pq.size()){
            maxi = max(maxi , pq.top());
            pq.pop();
        }
        return maxi<=m;
    }
};
    
*/
    
    