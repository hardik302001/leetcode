// the fact that i suck at ........ bruh

// oohk , so its a ezpz pq ques
// obv eat the early rotting apple first
// add apple for n days and eat simulataneously
// go day by day and eat apple until pq is empty ( or until apples aren't rotted , mf..)

// courtesy lc by fraz yt


class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int , int> , vector<pair< int, int>> , greater<pair<int, int>>>pq;  //min heap bcz early rotting time
            
        int ans = 0;
        int i = 0;
        while(i<n or pq.size()){ // current day = i
            
            // add apple only if we are <= n days
            if(i<n) pq.push({i + days[i] , apples[i]});
            
            // eat current day apples (if you are able to eat)
            while(pq.size()){
                if(pq.top().first<=i or pq.top().second==0 ){
                    pq.pop();
                }else{
                    auto [day , apple ] = pq.top();
                    pq.pop();
                    apple--;
                    pq.push({day , apple});

                    ans++;
                    break;         // bcz you can only eat only one apple in a day..
                }
            }
            
            i++;
        }
            
        return ans;
    }
};