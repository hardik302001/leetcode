// greedy , priority queue
// When one takes the stone, they not only get the points, but they take them away from the other player too.
// Greedily choose the stone with the maximum aliceValues[i] + bobValues[i].

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int, int>>pq;
        int n = a.size();
        
        for(int i = 0;i<n;i++){
            pq.push({a[i]+b[i] , i});
        }
        
        int al = 0;
        int bo = 0;
        int turn = 1;   // alice
        
        while(pq.size()){
            auto [ topa , ind] = pq.top();
            pq.pop();
            if(turn){
                al+=a[ind]; 
            }else{
                bo+=b[ind];
            }
            turn = 1 - turn;
        }
        
        if(al==bo) return 0;
        else if(al>bo) return 1;
        else return -1;
        
    }
};