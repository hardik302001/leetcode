//similar to https://leetcode.com/problems/maximum-earnings-from-taxi/

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/917256/C%2B%2B-DP-Solution-in-O(n2)-and-O(nlogn)-time
//also see prev soln, O(n2)
//this is o(nlogn)


class Solution{
public:


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int> > ans;
        vector<int> dp;
        for(int i=0;i<n;i++)
        {
            ans.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(ans.begin(),ans.end()); // sort using end time
		
        for(auto i : ans){
            cout<<i[1] <<" "<<i[0]<<" "<<i[2]<<endl;
        }
        
        cout<<endl;
        
        dp.push_back(ans[0][2]); //considering sbse chota endtimewala bcz isse phele toh kuch h  hi nhi
        int index,temp;
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
                 
            if(index!=-1)                       //considering current timearray   
                temp = dp[index] + ans[i][2];
            else temp = ans[i][2];
            
            
            dp.push_back(max(temp,dp[i-1]));    //dp[i-1] for ignoring current timestamp
        }
        
        return dp[n-1];
    }
    
};