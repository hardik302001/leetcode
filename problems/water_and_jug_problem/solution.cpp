// https://leetcode.com/problems/water-and-jug-problem/discuss/83720/Clear-Explanation-of-Why-Using-GCD
//  O(n+m)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0 or x==z or y==z) return true;
        if(x+y==z) return true;
        if(x+y<z) return false;
        if(x%2==0 && y%2==0 && z%2!=0)//cannot measure odd capacity using even capacity jugs 
            return false;
        return (z % __gcd(x, y) == 0);
    }

};



// BFS CAN GIVE TLE...BUT ITS GOOD FROM INTERVIEW POV!
// O(n*m)
/*
	The following operations could be done to a jug:
    1. Empty jug1 into jug2 (But there might be some left in jug1)
    2. Emoty jug2 into jug1 (But there might be some left in jug2)
    3. Fill jug1 completely
    4. Fill jug2 completely
    5. Empty jug1 
    6. Empty jug2
*/
/*
class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        
        if(jug1 + jug2 < target)
            return 0;
        
        queue<pair<int,int>> q;
        set<pair<int,int>> st;
        st.insert({jug1 , jug2});
        q.push({jug1 , jug2});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first , y = top.second;
            if(x+y == target)
                return 1;
            int X,Y;
            //1
            X = x - min(x , jug2-y);
            Y = y + min(x , jug2-y);
            if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            }                
            //2
            Y = y - min(y, jug1-x);
            X = x + min(y, jug1-x);
            if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            } 
            //3 
            X = jug1 ; Y = y;
             if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            }
            //4 
            X = x ; Y = jug2;
             if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            }
            //5
            X = 0 ; Y = y;
            if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            } 
            //6 
            X = x ; Y =0;
            if(st.count({X,Y})==0){
                st.insert({X,Y});
                q.push({X,Y});
            }
               
        }        
        return false;
    }
};
*/

/*
Time Complexity:
In jug 1, the capacity can range from 0 to jug1Capacity.
Similarly, in jug 2, the capacity can range from 0 to jug2Capacity.
So, its time complexity is O(jug1Capacity * jug2Capacity) i.e quadratic

*/