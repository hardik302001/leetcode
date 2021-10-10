

class StockPrice {
public:
    unordered_map<int, int> prices = {};
    map<int, int> ordered = {};
    int latestTime = -1;
    
    void update(int timestamp, int price) {
        if (prices.find(timestamp) != prices.end()) {
            int prevPrice = prices[timestamp];
            ordered[prevPrice]--;
            if (ordered[prevPrice] == 0)
                ordered.erase(prevPrice);
        }
        prices[timestamp] = price;
        ordered[price]++;
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return prices[latestTime];
    }
    
    int maximum() {
        //return ordered.rbegin()->first;                 //returns, iterator of key-pair tuple at last position can only be accessed this way ->
        
        
        //can alos be done as, by deiterating using *
        return (*ordered.rbegin()).first;
    }
    
    int minimum() {
        // return ordered.begin()->first;     //return iterator key-value pair at first position 
        
        
        return (*ordered.begin()).first;
    }
};