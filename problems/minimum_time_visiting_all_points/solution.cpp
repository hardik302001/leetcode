/*
How do you calculate Chebyshev distance?
Image result for chebyshev distance
The Chebyshev distance calculation, commonly known as the "maximum metric" in mathematics, measures distance between two points as the maximum difference over any of their axis values. In a 2D grid, for instance, if we have two points (x1, y1), and (x2, y2), the Chebyshev distance between is max(y2 - y1, x2 - x1).

https://chris3606.github.io/GoRogue/articles/grid_components/measuring-distance.html

*/


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;
        int n = p.size();
        int px = p[0][0];
        int py = p[0][1];
        for(int i = 1;i<n;i++){
            ans = ans + solve(p[i][0] , p[i][1] , px , py);
            px = p[i][0];
            py = p[i][1];
        }
        
        return ans;
    }
    
    int solve(int px , int py , int cx , int cy){
        return max(abs(cx-px) , abs(cy - py));
    }
};