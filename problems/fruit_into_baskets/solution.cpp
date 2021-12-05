//tc = o(n)
//sc O(n)

//sliding window
//code similar to : https://leetcode.com/problems/max-consecutive-ones-iii/submissions/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> m;
        int n=tree.size();
        int l=0,r=0,ma=0,ct=0;
        while(r<n){
            if(m[tree[r]]==0) ct++;
            m[tree[r]]++;
            
            while(ct>2){
                m[tree[l]]--;
                if(m[tree[l]]==0) ct--;
                l++;
            }
            
            ma=max(ma,r-l+1);
            
            r++;
        }
        return ma;
    }
};