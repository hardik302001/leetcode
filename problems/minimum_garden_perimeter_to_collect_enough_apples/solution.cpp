typedef long long ll;
class Solution {
public:
    long long minimumPerimeter(long long apples) {
        ll i = 1;
        ll total = 0;
        while(1){
            ll temp = 12*i*i;
            total += temp;
            if(total >= apples) break;
            i++;
        }
        return 8*i;
    }
};