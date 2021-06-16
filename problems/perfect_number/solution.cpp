//TILL root n , more optimised

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        for(int i =2 ; i*i<=num; i++ ){
            if (num%i==0){
                sum = sum + i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        if(num==1){
            return false;
        }
        return sum==num;
    }
};