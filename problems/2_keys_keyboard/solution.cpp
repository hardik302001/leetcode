/* On caculating for a few numbers , we can observe that for every prime number n, no. of 
operations = n as they have no factors. Also,for non-prime number 
n= (a^b)*(c^d)... where a and c are prime factors, min operations= (a*b) + (c*d) + ...
*/

class Solution {
public:        
    int minSteps(int n) {
        int ans=0,i=2;
        unordered_map<int , int>m;
        while(n>1){ //finding prime factors and adding divisible ones into ans
            int c = 0;
            while(n%i==0) {
                c++;
                n/=i;
            }
            if(c>0){
                m[i]=c;
            }
            i++;
        }
        
        
        for(auto it:m){
            ans+=it.first*it.second;
        }
        return ans;

    }
};
