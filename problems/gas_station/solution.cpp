/*

In my humble opinion, this is more easy to understand,

difference at index i is difference += gas[i] - cost[i]

Basically we make two passes to the array and if am able to reach my starting position again with difference being positive that index is my answer, if difference becomes negative anywhere I start the counting again and make difference 0 again.
    
    */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff = 0, n = gas.size(), count = 0;
        for(int i=0; i<2*n; i++){
            diff += (gas[i % n] - cost[i % n]);
            count++;
            if( diff < 0 ){
                count = 0;
                diff = 0;
            }
            if( count == n) {
                cout << i;
                return (i+1) % n;
            }
        }
        return -1;
    }
};
        

