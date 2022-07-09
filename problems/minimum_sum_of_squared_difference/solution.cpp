// Best strategy is to decrease the highest difference every time but the if we try to decrease every element one by one it will give TLE rather than that lets store the count of every difference as well, and then decrease the numbers. This way our k1 and k2 will not be decreased by one every time but by the count of the biggest diffrence
/*
class Solution {
public:
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        unordered_map<long long, long long > mp;
        for(int i = 0; i < n; ++i) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        long long tot = k1 + k2;
        
        priority_queue<pair<int , int>> pq;    // max heap with (val , freq)
        for(auto [x, y]: mp) {
            if(x == 0) continue;
            pq.push({x, y});
        }
        
        
        while(!pq.empty() and tot > 0) {
            pair<int, int> v = pq.top();
            pq.pop();
            
            if(pq.size() == 0) {   // it means only one element with some freq
                long long  mn = min(tot, v.second);    
                tot -= mn;
                v.second -= mn;
                // ex. pq = [4, 5] 4 with freq 5
                // tot = 2, it means we get [3, 3]( decreased ) and [2,5]( left bcz of insufficient tot )
                
                
                if(v.first - 1 > 0) pq.push({v.first - 1, mn});  // decrease to (element - 1) 
                if(v.second > 0) pq.push({v.first , v.second});  // all are decreased, so freq = 0, so we nothing left without decrement
            } 
            else {          // many elements are present
                long long  mn = min(tot, v.second);
                tot -= mn;
                v.second -= mn;
                // ex. pq = [4, 5] , [3, 2] 
                // tot = 2, it means we get [3, 3] and [2,5] , but we have 3 as key , so rather making a new group , we will update the frq of pair with existing value..
                
                
                if(v.second > 0) pq.push({v.first , v.second});   // push the left values, undecreased  
                
                if(pq.top().first == v.first - 1) {  // if we have (v..first-1) already , then update its freq
                    pair<int , int> newv = pq.top();
                    pq.pop();
                    newv.second += mn;
                    pq.push({newv.first , newv.second});
                } else if(v.first - 1 > 0) {    // if it do not exist and is > 0, we create a new pair for it..
                    pq.push({v.first - 1, mn});
                }
            }
        }
        

        long long  ans = 0;
        while(!pq.empty()) {
            pair<int , int> v = pq.top();
            pq.pop();
            
            long long res = 1;
            res*=v.first;
            res*=v.first;
            res*=v.second;
            ans+=res;
        }
        return ans;
    }
    
    
    long long  min(long long  a , long long  b) {
        return (a<b)?a:b;
    }
};

*/

// --------------------------------------------------------------------------------------
// same thing small code
class Solution{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
       // get maximum difference
        int n=nums1.size(),M=0;
        for(int i=0;i<n;i++) M=max(M,abs(nums1[i]-nums2[i]));
        
        vector<int> bucket(M+1);
        for(int i = 0 ; i<n; ++i) bucket[abs(nums1[i]-nums2[i])]++;
        int k = k1 + k2;
        for(int i = M; i > 0; --i) {
            if(bucket[i] > 0) {
                int minus = min(bucket[i], k);
                bucket[i] -= minus;
                bucket[i-1] += minus;
                k -= minus;
            }
        }
        long long ans = 0;
        for(long long i = M; i > 0; --i) 
            ans += bucket[i]*i*i;
        return ans;
    }
};