/*

pow(2,0) = 1
pow(2,1) = 2
pow(2,2) = 4
and so on.
observation - power of 2 always add extra 1 to all the previous results.*
so what can be done is, whenever you encounter a number n which is some power of 2 , add result from 0 to n-1 plus 1 for the subsequent numbers. that's it.
eg =
0 - 0
1 - which is a power of 2 (add res from 0 plus 1) - 0+1 = 1
2 - again a power of 2(add res from 0 to 1 plus 1 for subsequent n) - res[0]+1 =1
3 - res[1]+1 = 2
4 - again a power of 2(add res from 0 to 3 for subsequent n) - res[0]+1 = 1
5 - res[1]+1=2
6 - res[2] +1 =2
7 - res[3]+1 = 3
basically result from 4 to 7 is equal to the result from 0 to 3 plus 1
result from 8 to 15 is equal to the result from 0 to 7 plus 1 and so on.



*/

class Solution {
public:

vector<int> countBits(int num) {
        vector<int> res(num+1,0);                
        int start=0;        
        for(int curr=1;curr<=num;curr++){
            if(!(curr&curr-1)){                  //check if curr is power of two . 
                start=0;                
            }
            res[curr] = 1+res[start];         //add result from 0...curr-1 plus 1
            start++;
        }
        return res;
    
    }
};