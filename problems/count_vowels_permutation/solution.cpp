/*
a -> e
e -> a, i
i -> i           X
o -> u , i
u -> a
*/

class Solution {
public:
    int m = 1000000007;
    
    long long int dp[20005][6+97];
    long long int recur(int i , int cur ,  int n){
        if(i==n-1){
            return 1;    
        }
        if(dp[i][cur]!=-1){
            return dp[i][cur];
        }
        
        long long int c;
        if(cur+97=='a'){
            c = recur(i+1 , 'e'-97, n);
        }else if ( cur+97=='e'){
            c = (recur(i+1 , 'a'-97, n)%m + recur(i+1 , 'i'-97, n)%m)%m;
        }else if ( cur+97=='i'){
            c = (recur(i+1 , 'e'-97, n)%m + recur(i+1 , 'a'-97, n)%m + recur(i+1 , 'o'-97, n)%m + recur(i+1 , 'u'-97, n)%m)%m;
        }else if( cur+97 =='o'){
            c = (recur(i+1 , 'i'-97, n)%m + recur(i+1 , 'u'-97, n)%m)%m;
        }else if( cur+97=='u'){    
            c = recur(i+1 , 'a'-97, n)%m;
        }
        return dp[i][cur] = c%m;
    }
    
    int countVowelPermutation(int n) {
        memset(dp , -1  , sizeof dp);
        return (recur(0 , 'a'-97, n)%m + recur(0 ,'e'-97, n)%m + recur(0 ,'i'-97, n)%m + recur(0 ,'o'-97, n)%m + recur(0 ,'u'-97, n)%m)%m;
    }
};