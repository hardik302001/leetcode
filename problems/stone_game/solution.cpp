class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
        
        
};
    
    //why because ..
        //um approach is greedy,,we sort and reveerse, and do 1 + 3+ 5+ 7 terms...for alex
        //2 + 4 +6 8....for bob..
        
        //so its sorted ..so term at first place will be surely greater than second and second will be greater than third and third will be greater than fourth..so we can say 1+ 3> 2+ 4, it will be true..
        
        //we can do similar thing for whole array..
        
        //so finally 1 + 3+ 5...  > 2 + 4 +6 ...
        //so alex wins always