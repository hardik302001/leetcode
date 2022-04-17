class Solution {
public:
    long long arrangeCoins(long long n) {
        
        long long l = 1;
        long long r = n+1;
        
        while(l<r){
            long long m = l + (r-l)/2;
            if(check(m , n)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l-1;
        
    }
    
    
    bool check(long long m , long long n){
        return (m*(m+1)/2 > n);
    }
};