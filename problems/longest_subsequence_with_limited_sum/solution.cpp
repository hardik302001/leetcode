class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        // Required maxium size that's why it need to sorted (lower value come first).          
        sort(a.begin(),a.end());
        //question required return size of sum so need to calculate Prefix sum for 
        for(int i=1;i<a.size();i++){
            a[i]=a[i]+a[i-1];
        }
        
        for(int i=0;i<b.size();i++){
            //upper bound => It always return just upper index (if answer exits or not). 
            // Read more -> https://www.javatpoint.com/cpp-algorithm-upper_bound-function
            int ind = upper_bound(a.begin(),a.end(),b[i])-a.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};