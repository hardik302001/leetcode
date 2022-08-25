class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n)
            if((n % 3)==0) n /= 3;
            else if(n % 3 == 1) n--;   // power 0          
            else return false;        // no way to get 2 rem
        return true;
    }
};