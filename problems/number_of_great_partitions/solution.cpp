// tc: O(n*k)

/* 
if we go directly finding partition with sum atleast k, tc will be O(n*sum), TLE

so we go other way round,
part function 
 - Basic Knapsack -> Counts subsets with sum less than k 
works on finding left part of partition.
It finds count of such subseq whose sum is less than k. So, we consider this subseq as left part. now, whatsoever elements be in the right part, the partition will always be NOT GREAT.
Same thing can happen for right part also, thus we multiply total count by 2.

And subtract it from total subseq possible.

*/

class Solution {
public:
    using ll=long long;
    int mod = 1000000007;
    
    ll part(ll ind,vector <int> &nums,ll sum,int k,vector <vector<ll>> &dp){
        if(ind==nums.size()){
            if(sum<k){
                return 1;
            }
            return 0;    
        }
        if(dp[ind][sum]!=-1)  return dp[ind][sum];
        ll take=0;
        if(sum+nums[ind]<k)
            take=part(ind+1,nums,sum+nums[ind],k,dp);
        
        ll notTake=part(ind+1,nums,sum,k,dp);
        
        return dp[ind][sum]=(take%mod+notTake%mod)%mod;
    }


    int countPartitions(vector<int>& nums, int k){
        ll tot  = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
            tot+=nums[i];
        
        if(tot<2*k) return 0;
        
        ll total=1;
        for(int i=1;i<=n;i++){
            total=((total%mod)*2)%mod;
        }
        
        vector <vector<ll>> dp(n,vector<ll>(k+1,-1));

        //`2*part(0,nums,0,k,dp)` since ([1,2,3],[4]) & ([4],[1,2,3]) are counted seprately
        // but part function only considers ([4],[1,2,3])
        
        ll res=total-2*part(0,nums,0,k,dp); 
        if(res<0)res+=mod;
       
        return res;

    }
};

