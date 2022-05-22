// https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/discuss/2061821/C%2B%2B-with-explanation-Check-if-Slope-is-equal/



class Solution {
public:
    
    vector<int> getSlope(vector<vector<int>>& stockPrices, int i) {
        return {stockPrices[i][1]-stockPrices[i-1][1], stockPrices[i][0]-stockPrices[i-1][0]};
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() == 1) 
            return 0;
        
        sort(stockPrices.begin(),stockPrices.end());        
        vector<int> prev_slope = getSlope(stockPrices, 1);
        int ans = 1;

        for(int i=2; i<stockPrices.size(); ++i) {
            vector<int> slope = getSlope(stockPrices, i);
            if((long long)slope[0]*prev_slope[1] != (long long)slope[1]*prev_slope[0]) {
                prev_slope = slope;
                ++ans;
            }
        }
        return ans;
    }
};



/*

IT GAVE WA ON [[1,1],[500000000,499999999],[1000000000,999999998]]

class Solution:
    def minimumLines(self, l: List[List[int]]) -> int:
        l.sort()
        c = 0
        n = len(l)
        if n==1:
            return 0
        if  n==2:
            return 1
        p0 = l[0]
        p1 = l[1]
        ps = round(((p1[1]- p0[1])/(p1[0]-p0[0])) , 100)
        c+=1
        for i in range(2, n):
            cur = l[i]
            slope = round(((p1[1]- cur[1])/(p1[0]-cur[0])), 100)
            
            if(ps!=slope):
                c+=1
                ps = slope
            p1 = cur
        return c
                
                
            




*/