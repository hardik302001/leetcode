class MedianFinder {
public:
    
    priority_queue<int, vector<int>, greater<int>>mini;
    priority_queue<int> maxi;
    
    // max heap    min heap
    // by default go into max
    // maximum of ma heap shud be less than minimum of min heap
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() or maxi.top() > num ){  // most important line
            maxi.push(num);
        }else{
            mini.push(num);
        }
        
        
       // rebalance the two halfs to make sure the length difference is no larger than 1
        if(maxi.size() > (mini.size()+1))
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        else if(maxi.size()+1<mini.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }
        
        
    }
    
    double findMedian() {
        if(mini.size()==maxi.size()){
            return (mini.top() + maxi.top())/2.0;
        }else if(maxi.size()>mini.size()){
            return maxi.top();
        }else{
            return mini.top();
        }
        
    }
};

/*

Time Complexity for addNum() : O(logN)
Time Complexity for findMedian() : O(1)
Space Complexity: O(N)

*/
