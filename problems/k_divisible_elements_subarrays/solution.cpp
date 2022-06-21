// see constraints

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       int n = nums.size() ;
       set<string> st ;
       for(int i=0;i<n;i++){
           int temp = 0 ;
           string t = "" ;
           for(int j=i;j<n;j++){
               if(nums[j]%p==0) temp++ ;
               if(temp>k) break ;
               t += to_string(nums[j]) ;
               t += " " ;
               st.insert(t) ;
           }
       }
     return st.size() ;
    }
};