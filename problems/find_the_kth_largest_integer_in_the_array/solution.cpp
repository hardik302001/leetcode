//see all previous codes


//THE GOD RULE OF COMPARATERS!
//COMP in SORT() is differnet from comp in prioitoy queue

//COMP IN SORT()
/*
This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. 

Suppose we passes ( a,b) [note that a comes first], so whenever you will return true, a will come before b, 
whenever you return false b will come before a.

true means, the order of passing paramter to comp is maintained , and the output after comparing will also be returned in same order, if it is false, it means thatorder need to be swapped.

Ignore the case when a==b
*/


//Comp in PQ
/*
see syntax of writing compaarter for PQ. decalre a new class and write className as comparater, the name of compaarter is opertor() only!!

http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/ 

in MAX HEAP , if (a,b) is passed , return true when a is smaller than b, elsereturn false

in mEAN HEAP, if (a,b) is passed, return true when b is smaller than a, else return false.

ignore cases when a==b


*/













class NumStrMinComparator {
public:
    bool operator() (string &a, string &b) {
        if(a.size()<b.size()){
            return true;
        }
        else if(b.size()<a.size()){
            return false;
        }
        else{
            if(a<b){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrMinComparator> maxHeap;
        for (string& num : nums) {
            maxHeap.push(num);
        }
        k = k-1;
        while(k--){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};