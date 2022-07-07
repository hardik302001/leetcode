class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int c = 0;
        long long  cur = 0;
        
        
        int f = 1;
        for(int i = n-1 ; i>=0 ; i--){
            if(s[i]=='1'){
                if (!f or (n-i)>31) continue;   // (n-i) = count of digits seen , so 1 based indexing
                cur+= (1<<(n-1-i));            // (1<<(n-1-i)) = pow( 2 , (n-i-1)) , 0 based indexing 
                if(cur>k){  // if it cant handle it now, means it also cant handle it in future, so flag = 0, no more 1's needed 
                                // it means time up, so we need to only conisder 0 from now..
                    f = 0;
                }else{
                    c++;   // we can add current 1, 
                }
            }else{
                c++;
            }
        }
        
        
        return c;
        
    }
};