// x from front , so (k-x) from end
// also see: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/


// O(k3) , one for k , second for sum from beginning, third for sum from end

// Brute force
// TC:O(k*k)  : prefix sum
/*
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int s = 0;
        int ans = 0;
        for(int i = 0;i<=k;i++){
            if (i!=0) s = s + card[i-1];
            int sum = 0;
            int left = k- i;
            int j = 0;
            while(left--){
                sum = sum + card[card.size()-j-1];
                j = j + 1;
            }
            // cout<<sum + s<<endl;
            ans = max(ans , sum + s);
        }
        
        return ans;
    }
};
*/


// Brute force optimised
// TC:O(k)  : prefix sum + suffix sum


/*
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int s = 0;
        int ans = 0;
        vector<int> pref(k+1, 0);
        vector<int> suff(k+1, 0);
        for(int i = 0;i<k;i++){
            pref[i+1] = pref[i]+ card[i];
        }
        for(int i = 0;i<k;i++){
            suff[i+1] = suff[i]+ card[card.size() - 1 - i];
        }
        
//         for(auto i: pref){
//             cout<<i<<" ";
//         }
//         cout<<endl;
                
//         for(auto i: suff){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        for(int i = 0;i<=k;i++){
            int s = pref[i] + suff[k-i];
            ans = max(ans , s);
        }
        
        return ans;
    }
};


*/

/*
// recursion - TLE
class Solution {
public:
    
    int Pick(vector<int> v, int k, int i, int j){
        if(i>j || k==0){
            return 0;
        }
        int left = v[i]+Pick(v,k-1,i+1,j);
        int right = v[j]+Pick(v,k-1,i,j-1);
        int sum = max(left,right);
        return sum;
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        return Pick(cardPoints,k,0,cardPoints.size()-1);
    }
};

*/

// dp - TLE + MLE
/*
class Solution{
public:
    vector<vector<int>> dp;

    int go(int st, int en, int k, vector<int> &a) {
        if(k == 0) {
            return 0;
        }
        if(dp[st][en] != -1) {
            return dp[st][en];
        }

        return dp[st][en] = max(a[st] + go(st + 1, en, k - 1, a), a[en] + go(st, en - 1, k - 1, a));
    }

    int maxScore(vector<int>& a, int k) {
        int n = (int)a.size();
        dp.assign(n, vector<int>(n, -1));
        return go(0, n - 1, k, a);
    }
};
*/


// Sliding window of size (n- k)    O(n)
class Solution{
public:

    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int tot = 0;
        for (int i = n-1;i>=n-k;i--){
            tot += a[i];
        }
        
        int ans = tot;
        int l = 0;
        for(int r = n- k;r<n;r++){
            tot  = tot - a[r];
            tot = tot + a[l];
            l++;
            ans = max(ans, tot);
        }
        
        return ans;
        
    }
};


/*
same thing , sliding window

# minimise (n-k)

class Solution:
    def maxScore(self, arr: List[int], k: int) -> int:
        
        l = 0
        s = 0
        n = len(arr)
        if n==k:
            return sum(arr)
        
        ans = 10000000000000
        for r in range(n):
            s+=arr[r]
            if r-l+1==(n-k):
                ans = min(ans , s)
                s-=arr[l]
                l+=1
        # print(ans)
        return sum(arr)-ans

*/