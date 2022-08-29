// also see:  https://leetcode.com/submissions/detail/786588005/
// SLIDING WINDOW MEDIAN



class MedianFinder {
public:
    
    priority_queue<int, vector<int>, greater<int>>mini;
    priority_queue<int> maxi;
    
    // max heap    min heap
    // by default go into max
    // maximum of max heap shud be less than minimum of min heap
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() or maxi.top() > num ){  // most important line
            // bcz we want top of maxheap to be less than top of min heap , so if we get such element that is less than top of max heap , then we cant put it into min heap, bcz all elements of min heap should be greater than all elements of max heap..
            // so we put it into max heap...
            
            maxi.push(num);
        }else{         // if that is not the case, then it goes into min heap
            
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