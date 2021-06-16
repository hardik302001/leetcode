class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;//count of min(2,5) that will be always 5, so count of 5
                    //n! = 2^x * 5^y * ...... where x and y >= 0
        
        while(n){
            n = n/5;
            ans = ans + n;
        }
        
        
        return ans;
    }
};