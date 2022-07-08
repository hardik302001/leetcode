// also see: https://leetcode.com/problems/top-k-frequent-elements/
// also see: https://leetcode.com/problems/kth-largest-element-in-an-array/
// alse see: https://www.interviewbit.com/problems/maximum-sum-combinations/
// also see: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

//see all previous codes


//THE GOD RULE OF COMPARATERS!
//COMP in SORT() is differnet from comp in prioitoy queue

//COMP IN SORT()
/*
This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. 

Suppose we passes ( a,b ) [note that a comes first], so whenever you will return true, a will come before b, 
whenever you return false b will come before a.

true means, the order of passing paramter to comp is maintained , and the output after comparing will also be returned in same order, if it is false, it means thatorder need to be swapped.

Ignore the case when a==b
*/


//Comp in PQ
/*
see syntax of writing compaarter for PQ. decalre a new class and write className as comparater, the name of compaarter is opertor() only!!

http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/ 



in MAX HEAP , if (a,b) is passed , return true when a is smaller than b, else return false
bcz we arrange in small to big, so that when we pop, we get big(max) element
in miN HEAP, if (a,b) is passed, return true when b is smaller than a, else return false.

ignore cases when a==b

// WHY ARE W DONING IT THIS WAY! I DONT KNOW..   //

I thought it is analoguos to stack..first we put all elements to pq..according to making it maxheap or minheap..
then we pop..  (i assumed we always pop last element in pq, similar to stack\U0001f612)
so all decisions depend upon how we arrange elements while inserting them in pq, bcz its fixed that we will pop from end.


So lets see MAXHEAP, whenever we pop, we should get max elements..
it means we shud sort all elements in ascneding order(so that poping happens at end, and we get always max element)
to arrange in ascending order, whenever we get two entities in
custom comparators(suppose string a(first parameter) and string b(second parameter) ) , so according to condition(suppose here size), if a.size() > b.size()..it means a shud occur after b, but a is first parameter, so we shud return false, so that a can occur after b [ SAME AS WHAT WE DID IN CUSTOM SORTING , see above ]
Similarly , if a < b, return true , bcz we want smaller entities to occur in beginning..
Thus we get the rule..
in MAX HEAP , if (a,b) is passed , return true when a is smaller than b, else return false

Similar thing for minheap, we want bigger entities towards beginninig..
in MIN HEAP, if (a,b) is passed, return true when b is smaller than a, else return false.

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