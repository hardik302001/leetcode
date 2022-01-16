/*   BINARY  SERACH ON ANSWER           */

// same as : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// https://leetcode.com/problems/maximum-running-time-of-n-computers/discuss/1692979/Java-Simple-Solution-w.-Explanation
/*
Observations

If the computers cannot run simultaneously for a minutes, then definitely they cannot run simultaneously for b > a minutes.
During a simultaneous run of a minutes, each battery, no matter how long it can run, can "contribute" a maximum of a minutes to the total running time.
Solution

Based on Observation #1, perform a Binary Search on the maximum number of minutes for the simultaneous run attainable.
The lower and upper bound for the Binary Search are 0 (cannot run at all) and sum(batteries[i]) / n (the computers' total running time cannot exceed total battery amounts)
During each search, check whether all batteries "contribute" enough for the total running time required for this simultaneous run, based on Observation #2.
The running time would be O(m \lg n) where m = sum(batteries[i]) and n = batteries.length are the total sum of all batteries, and number of batteries.


*/
class Solution {
public:
    bool fun(vector<int>& a, long long x, long long k){
        long long val = x*k;
        long long curbatsum = 0;
        for(int i=0; i<a.size(); i++){
            curbatsum += min((long long)a[i],k);
        }
        return val <= curbatsum;
    }
    long long maxRunTime(int n, vector<int>& a) {
        long long sum = 0;
        for(auto i : a){
            sum += i;
        }
        long long ans = 0;
        long long l = 0, r = sum;
        
        // we need maximum so we start from r!
        if(fun(a, n , r)) return r;    // bcz while (l<r) will not check for r, (bcz when l = mid +1 [mid+1==r], then it will be l==r, so it will break!)
        
        while(l < r){
            long long mid = l + (r-l)/2;
            if(fun(a,n,mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return ans;
    }
};