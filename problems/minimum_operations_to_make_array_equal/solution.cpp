class Solution {
public:
    int minOperations(int n) {
        if(n==1){
            return 0;
        }
        if(n%2==1){
            int p = (n-1)/2;
            return p*(p+1);
        }
        else{
            int p = n/2;
            return p*p;
        }
    }
};
