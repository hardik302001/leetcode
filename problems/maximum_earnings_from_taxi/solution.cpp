
//see prev codes(the first one) also, there we are working on taxi points individualy , but here we are working with rides interval only!
// exact same problem :  https://leetcode.com/problems/maximum-profit-in-job-scheduling/

//dp[i] gives the optimal cost of reaching index i (or taxis taken/not taken to reach index i)


class Solution {
public:
    long long maxTaxiEarnings(int nn, vector<vector<int>>& rides) {
        long long n  = rides.size();        //we will be working on size of rides, rather than n actual taxi points
        vector<vector<long long> > ans;
        vector<long long> dp;
        for(int i=0;i<n;i++)
        {
            ans.push_back({rides[i][1], rides[i][0], rides[i][1] - rides[i][0] + rides[i][2]});
        }
        sort(ans.begin(),ans.end()); // sort using end time
		
        dp.push_back(ans[0][2]); //considering sbse chota endtimewala bcz isse phele toh kuch h hi nhi
        long long index,temp;
        for(int i=1;i<n;i++)
        {
            index=-1;    //we are finding the highest possible index ,less than current interval index , having endtime just less than/ equal to start time of current interval 
            int l=0,h=i-1;
            while(l<=h)
            {
                int m = (l+h)/2;
                if(ans[m][0]<=ans[i][1])
                {
                    if (ans[m+1][0] <= ans[i][1]) 
                        l = m + 1; 
                    else
                    {
                        index = m;
                        break;
                    } 
                }
                else
                    h = m-1;
            }
                 
            if(index!=-1)                       //considering current ridearray
                temp = dp[index] + ans[i][2];
            else temp = ans[i][2];            //if no interval found previously current interval , and we have to conisder it
            
           
            dp.push_back(max(temp,dp[i-1]));    //dp[i-1] for ignoring current ridearray
        }        
        return dp[n-1];
    }      
};

