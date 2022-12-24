
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans=0;
        int n=forts.size();
        for(int i=0;i<n;i++)
        {
            if(forts[i]!=1)continue;
            int cnt=0;
            for(int j=i+1;j<n;j++)
            {
                if(forts[j]==0)cnt++;
                else 
                {
                    if(forts[j]==-1)
                    {
                        ans=max(ans,cnt);
                    }
                    break;
                }
            }
            cnt=0;
            for(int j=i-1;j>=0;j--)
            {
                if(forts[j]==0)cnt++;
                else 
                {
                    if(forts[j]==-1)
                    {
                        ans=max(ans,cnt);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};