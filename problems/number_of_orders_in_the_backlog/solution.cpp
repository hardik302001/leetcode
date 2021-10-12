class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy; // max-heap 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sell; // min-heap 
        
        for (auto& order : orders) {
            auto price = order[0], qty = order[1], type = order[2]; 
            
            if (type == 0) buy.emplace(price, qty); //to improve code quality 
            else sell.emplace(price, qty); 
            
            while (size(buy) && size(sell) && buy.top().first >= sell.top().first) {   //last conditionto improve code quality
                auto [bp, bq] = buy.top(); buy.pop(); 
                auto [sp, sq] = sell.top(); sell.pop(); 
                if (bq > sq) {
                    bq -= sq; 
                    buy.emplace(bp, bq); 
                } else if (bq < sq) {
                    sq -= bq; 
                    sell.emplace(sp, sq); 
                }
            }
        }
        
        int ans = 0; 
        while (size(buy)) { ans = (ans + buy.top().second) % 1'000'000'007; buy.pop(); }
        while (size(sell)) { ans = (ans + sell.top().second) % 1'000'000'007; sell.pop(); }
        return ans; 
    }
};