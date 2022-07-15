// greedy , simulation

class Solution {
public:
    int minCost(vector<int>& s, vector<int>& e, vector<int>& r, vector<int>& c) {
        long long sum=0;
        if(s[0]>e[0])
        {
            int idx=s[0];
            while(idx!=e[0])
            {
                sum+=r[--idx];
            }
        }
        else if(s[0]<e[0])
        {
            int idx=s[0];
            while(idx!=e[0])
            {
                sum+=r[++idx];
            }
        }
        
        if(s[1]>e[1])
        {
            int idx=s[1];
            while(idx!=e[1])
            {
                sum+=c[--idx];
            }
        }
        else if(s[1]<e[1])
        {
            int idx=s[1];
            while(idx!=e[1])
            {
                sum+=c[++idx];
            }
        }
        
        return sum;
    }
};