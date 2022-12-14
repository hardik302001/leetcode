class Solution {
public:
    vector<int>ans;
    int ma = 0;
    void recur(int i  , int tot , vector<int>&alice , vector<int>&bob, int sum){
        if(i<0){
            if(sum>ma){
                ma = sum; 
                bob[0]+=tot;
                ans = bob;
                bob[0]-=tot;
            }
            return;
        }
        
        if(tot>=(alice[i]+1)){
            bob[i]+= (alice[i]+1);
            recur(i-1 , tot - alice[i]-1 , alice , bob, sum + i);
            bob[i]-= (alice[i]+1);
        }
        
        recur(i-1 , tot , alice, bob, sum);
        
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& alice) {
        vector<int>bob(12 , 0);
        recur(11 , n , alice , bob, 0);
        return ans;
    }
};