class Solution {
public:
    int commonFactors(int a, int b) {
        map<int, int>m1, m2;
        int ans = 0;
        for(int i = 1;i<=1000;i++){
            if(a%i==0){
                m1[i]++;
            }
            if(b%i==0){
                m2[i]++;
            }
            if(m1[i] and m2[i]) ans++;
        }
        
        
       
        return ans;
        
    }
};