# define ll long long
class Solution {
public:
    
    // no of subarray having subarray sum equal k
     long long solve( int s , int e ,vector<int>& nums, int need) {
        map<long long int ,int> mp; // prefix sum recorder
        long long cc = 0; // number of found subarray
        long long cum=0; // cumulated sum
        mp[0]++; // to take into account those subarrays that begin with index 0
        for(int i=s;i<e;i++){
            cum += nums[i];
            cc += mp[cum-need];
            mp[cum]++;
        }     
        return cc;
    }
    

    long long countSubarrays(vector<int>& v, int k) {
        int ind = -1;
        int n = v.size();        
        vector<int>ss(n, 0), bb(n, 0), dif(n, 0);
        for(int i = 0;i<n;i++){
            if(v[i]==k) {
                ind = i;
                break;
            }
        }

        // freq of elements smaller than v[k] , and bigger than v[k]    
        for(int i = 0 ; i < n; i++){
            bb[i] = v[i] > v[ind] ;
            ss[i] = v[i] < v[ind];
            dif[i] = ss[i] - bb[i];
        }
        
        // for median , we must have no of smaller and bigger elements equal in odd subarray  (we need dif[i] ==0 )
        // and bigger elemnets must be 1 more than smaller elements in even subarray ( so we need dif[i] = -1)
        
        
        // total subarray with sum equal x with v[k] as median will be ( subarray sum equal x in (0:n) - subarray sum (0:ind) - subarray sum(ind+1 :n))
        // we must include v[k] , as it is median , so we are doing tot - exclusing median
        int odd = solve(0, n, dif, 0) - solve(0, ind, dif, 0) - solve(ind+1, n, dif, 0);
        int even = solve(0, n, dif, -1) - solve(0, ind, dif, -1) - solve(ind+1, n, dif, -1);
        return even + odd;
    }
};