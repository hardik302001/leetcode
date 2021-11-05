class Solution {
public:
    int arrangeCoins(int n) {
        
        long long l=1,r=n;
        
        while(l<r){
           long long mid =l+(r-l)/2;
            
           long long p=mid*(mid+1)/2;
            
            if(r-l==1){
                if(r*(r+1)/2<=n) return r;
                return l;
            }
            
            
            if(p==n) return mid;
            if(p<n) {
               
                l=mid;
            }
            else 
                r=mid-1;
            
        }
        return l;
        
        
    }
};