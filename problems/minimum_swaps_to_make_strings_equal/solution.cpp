// The two first examples give the key to the solution
// Everytime there is a difference it is either an (x,y) pair or an (y,x) pair
// As seen in example 1, two pairs of (x,y) or two pairs of (y,x) can be fixed in one swap
// But one pair of (x,y) and one pair of (y,x) need two swaps to be fixed, as seen in example 2

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0, yx=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]=='x' && s2[i]=='y') xy++;
            else if(s1[i]=='y' && s2[i]=='x') yx++;
        }
        if(xy%2 != yx%2) return -1;
        return xy/2 + yx/2 + (xy%2) * 2;
    }
};
