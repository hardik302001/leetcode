/*
https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/
SAME QUES, BUT THE DIFFERENCE IS WE HAVE TO DO ONLY ADJACENT SWAPS!
HERE IN LEETCODE QIES, WE CAN DO ANY SWAPS!

def swapCount(s):
    # Stores total number of left and 
    # right brackets encountered
    countLeft = 0
    countRight = 0
     
    # Swap stores the number of swaps 
    # required imbalance maintains the
    # number of imbalance pair
    swap = 0
    imbalance = 0;
     
    for i in range(len(s)):
        if s[i] == '[':
             
            # Increment count of left bracket
            countLeft += 1
             
            if imbalance > 0:
                 
                # Swaps count is last swap
                # count + total number
                # imbalanced brackets
                swap += imbalance
                 
                # Imbalance decremented by 1
                # as it solved only one
                # imbalance of left and right
                imbalance -= 1
                 
        elif s[i] == ']':
             
            # Increment count of right bracket
            countRight += 1
             
            # Imbalance is reset to current
            # difference between left and
            # right brackets
            imbalance = (countRight - countLeft)
 
    return swap
 

*/



/*


The idea is to traverse our string and check the biggest possible disbalance. For example if we look at ]]][]]][[[[[, for traversals we have:
-1, -2, -3, -2, -3, -4, -5, -4, -3, -2, -1, 0 and the biggest disbalance is equal to 5. What we can do in one swap of brackets is to decreas it at most by 2: for this we need to take the leftest ] with negative balance and the rightest [ with negative balance and change them. For example in our case we have:

[]][]]][[[[] : [1, 0, -1, 0, -1, -2, -3, -2, -1, 0, 1, 0]

[][[]]][][[] : [1, 0, 1, 2, 1, 0, -1, 0, -1, 0, 1, 0]

[][[]][[]][] : [1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0]


----------------------------------------------------------------------------------------------------------------------------

other soln:  


e.g. s = "[]][][[]"
if we iterate over s and maintain a stack like variable c which increses with [ and decreses with ],
then at last, if we get c = 0 and c >= 0 at any point of traverse, then only s is valid
as c<0 means, ] is before [, which is inbalanced string
but, here in this problem ,we can be given an imbalanced string as well, so c can be negative as well.
that's the same we are suppose to find how much imbalanced it is, i.e. what is the most negative value of c we can get
e.g .
_][[] ] ] [[
-1010-1-2-10 -> c
here, we are getting mx = -2 as maximum negative value, which we can consider as "parts to repair" in easy words.
so this much charactors are invalid, hence we can find the number swaps by it,
as each swaps can repair 2 charactors,
answer will be ceil(float(abs(mx))/2)

Code:
    
*/

class Solution {
public:
    int minSwaps(string s) {
        int mx = INT_MAX;    // tracker for the most negative value (minimum value) of c
        int c = 0;
        for(auto i:s)    
        {
            if(i=='[') c++;
            else c--; 
            
            mx = min(mx, c);
        }
        return ceil(double(abs(mx))/2);
    }
};