class Solution {
public:

    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        int count_b=0;
        //dp(i) gives the number of characters to be deleted to make substring s(0,i) valid
        for(int i=0;i<n;i++)
        {
            //it is always valid to append b at the 
            if (s[i]=='b') dp[i+1]=dp[i],count_b++;
            else
            {
                //two cases arise
                //case1: we remove a
                //case2: keep a, then count_b number of characters will need to be removed
                dp[i+1]=min(dp[i]+1,count_b);
            }
        }
        return dp[n];

    }
};





/*

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> a(n,0);
        vector<int> b(n,0);
        int c=0;
        for(int i=0;i<n;i++)
        {
            b[i]=c;
            if (s[i]=='b') c++;
        }
        c=0;
        for(int i=n-1;i>=0;i--)
        {
            a[i]=c;
            if (s[i]=='a') c++;
        }
        int ans=min(b[n-1], a[0]);
        for(int i=0;i<n;i++) ans=min(ans,a[i]+b[i]);
        return ans;

    }
};

*/