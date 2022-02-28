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


// we want maximum here..
/*

# minimise maximum, so we return do hi = mid for valid case, and return low

# if it was maximise minimum, then we will do li = mid +1 for valid case and return li - 1
# keep something extra in r...bcz (l<r) and we are returning l-1, so we wont chcek ever on r, so keep extra
#                        OR
# keep a speerate variable ans , and equate ans to the value, whenever we get valid result for answer from function
# see: https://leetcode.com/problems/maximum-running-time-of-n-computers/submissions/

*/

class Solution {
public:
    bool fun(vector<int>& a, long long n, long long k){
        long long val = n*k;
        long long curbatsum = 0;
        for(int i=0; i<a.size(); i++){
            curbatsum += min((long long)a[i],k);
        }
        // why we are doing min here ??
        /*
         I was also confused why we are only considering k when we have bat>=k.
The idea is that,

Yeah, we would greedily want to use the left battery units (i.e. a[i] -k) to other pc, where battery is less than k.
But one thing to notice here is that we can help others pc, only when we are done with our work. That is only when, we have used this current battery for k minutes on our current assigned pc.
So , we would help other pc with our extra battery units ( a[i] - k) after k minutes. But , but , but, after k minutes our experiment is over. So, we cant use more than k units of battery where a[i]>=k.

For bat<k, we can only use a[i] units of battery.
        
        */
        
        
        return val <= curbatsum;
    }
    
    
    long long maxRunTime(int n, vector<int>& a) {
        long long sum = 0;
        for(auto i : a){
            sum += i;
        }
        long long l = 0, r = sum+1;  // always keep something extra in r, bcz we are considering l<r, so we will never see R

        while(l < r){
            long long mid = l + (r-l)/2;
            if(fun(a,n,mid)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l-1;
    }
};