
// explore from back 
class Solution {
public:

    bool ispower(int a) {
        while(a % 2 == 0) a/=2;
        return a==1;
    }
    
    bool isReachable(int targetX, int targetY) {
        while(targetX > 0 and targetY > 0) {
            if(targetX == 1 or targetY == 1) {
                return true;
            }
            if(targetX % 2 == 0) {
                targetX /= 2;
                continue;
            }
            if(targetY % 2 == 0) {
                targetY /= 2;
                continue;
            }
            if(targetX > targetY) {
                targetX -= targetY;
            } else {
                targetY -= targetX;
            }
        }
        
        return false;
    }
};


// second solution is gcd
// conditions are gcd only , see py soln