# define ll long long

// backtracking
/*
class Solution {
public:
        
    int res = INT_MAX;

    void solve(vector<int>&cookies , int ind , int k , vector<int>&s){
        if(ind==cookies.size()){
            int ma = 0;
            for(int x = 0;x<k;x++){
                ma = max(ma , s[x]);
            }
            res = min(res , ma);
            return;
        }
        
        
        for(int x = 0;x<k;x++){
            s[x] += cookies[ind];
            solve(cookies , ind+1 , k, s);
            s[x]-=cookies[ind];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>s(8 , 0);
        solve(cookies , 0 , k, s);
        return res;
        
    }
};

*/



// Binary search
// we cant do binary seacrh bcz we dont have subarrray here.. we can choose non contiguous subarray...
// or we consider every permutuation and then do binary search (as n = 8)


/*
binary search q, the binary search property is can i divide array into k parts with each part having sum<=s. if nnot so, then
any value less than s wont work, otherwise if true look for even lesser value of s for ans, give the min such value using binary search
*/



class Solution {
public:
    
    int res = INT_MAX;
    bool check(int s, vector<int>&a, int k)
    {
        int parts = 1;
        ll sum = 0;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]>s) return false;
            sum+=a[i];
            if(sum >s)
            {
                sum=a[i];
                parts++;
            }
        }
        return parts<=k;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end());
        do{
            ll l = 0;
            ll r = accumulate(cookies.begin(), cookies.end(), 0)+1;

            while(l<r)
            {
                int mid = (l+r)/2;
                if(check(mid,cookies,k))    r = mid;     
                else                        l = mid+1;
            }
            
            // now l is the minimum fairness of current vector
            res = min(res , int(l));

        } while(next_permutation(cookies.begin(), cookies.end()));
        
        return res;
    }
};

