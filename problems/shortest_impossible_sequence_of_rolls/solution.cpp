class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int len = 1;
        set<int> data ;
        
        for (int i = 0; i < rolls.size(); i++) {
            data.insert(rolls[i]);
            
            if (data.size() == k) {
                len++;
                data.clear();   // bcz we always need a new set of k integers, as prev len sets + one new set of k inetegers will form a set of (len+1). 
            }
        }
        
        return len;
    }
};


// The idea is if you're given that you can create a L length array of all permutation with atleast M length of given array used from the begining, then if you do not find all the k numbers after this m length then L + 1 length can not be created.

// dry run some test case and you will understand it.
/*
[1,1,2,3,3,2]
3


we cannot find [2,1] , so ans = 2
*/