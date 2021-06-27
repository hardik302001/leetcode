/*

Intuition:
We need to maximize even positions, and minimize odd positions sum
So we must pick big elements for even pos and small for odd pos such that it is most optimal for us

We need to get best subarray, we can include an element then we can

keep it or,
replace with other element, it will mean we skipped the earlier present number
Also we will try to have one more element in even array if the last picked element was odd, to maximize the even sum

We can approach it like, first pick 0th number for even array
Now traverse in array with i=1,

There are 2 cases -

if previous picked was odd

then this number can replace the previously picked odd
or it can be put in evens array
if previous picked was even

then this number can replace the previously picked even
or it can be put in odds array
Now, we need to think when to perform which operation from them

if previous picked was even

if this num >= even.back then it's optimal to use it in even array to maximize their sum
because if we had included it in odds it must have subtracted it's not good
and if we have skipped it, instead of skipping this skip previous because it has more value, it will add more than previously picked hence it will always be optimal
else we use it for subtraction
if previous picked was odd

if this num < odd.back then we should include it in even array to minimize odd elements
(similarly for less number in odds array as there was for large in evens array)
else we use it for addition
At last if even and odd size are same then pop one from odd back, we need to minimize the odd sum
You can understand this approach more clearly after the dry run


Dry Run:
nums = [6,2,1,2,4,5]
evens = {6}
odds = {}
i = 1
num = 2
now, we can put it in odd or in even
our previous move was in even
so this time i can replace the even's last, or insert in odd
but it is less than even's back, so put it in odd

evens = {6}
odds = {2}
i = 2
num = 1
now, we can put it in odd or in even
our previous move was in odd
so this time i can replace the odd's last, or insert in even
but i can see it is less than odd's back, so i should replace it with that so that we subtract less
so here it becomes like we skipped the 2 and didn't include it in neither odd nor even and picked 1

evens = {6}
odds = {1}
i = 3
num = 2
we shouldn't replace it with odd, else it will maximize it
so put it in even, if we will find a bigger number we will replace it later

evens = {6,2}
odds = {1}
i = 4
num = 4
our previous move was in even
so this time we can replace the even's last, or insert in odd
we should replace it with even's last

evens = {6,4}
odds = {1}
i = 5
num = 5
our previous move was in even
so this time we can replace the even's last, or insert in odd
we should replace it with even's last

evens = {6,5}
odds = {1}
So now we can see, we have chosen alternatively max in even and min in odd
ans = 6 - 1 + 5

also if even and odd size are equal
then pop one from odds's back, it will also minimise the odd

I used dequeue, but we can use vectors also


Code :


*/
#define ll long long

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
      ll ans = 0;
      
      // two dequeues for alternatively putting or replacing last elements at even odd pos
      deque<ll> evens;
      evens.push_back(nums[0]);
      
      deque<ll> odds;
      
      // if prev op was in odd then prev = 0, else prev = 1
      int prev = 1;
      
      for(int i = 0; i < nums.size(); ++i){
        
        // we had previously inserted in odd
        if(prev == 1){
          
          // if this number is >= odd's back we should put it in odd to maximize odd sum
          if(nums[i] >= evens.back()){
            evens.pop_back();
            evens.push_back(nums[i]);
            prev = 1;
          }
          // number is < odd's back, so insert it in even
          else {
            odds.push_back(nums[i]);
            prev = 0;
          } 
        }
        
        // we had previously inserted in even
        else {
          
          // if this number is < even's back we should put it in even to minimize even sum
          if(nums[i] < odds.back()){
            odds.pop_back();
            odds.push_back(nums[i]);
            prev = 0;
          }
          // number is >= even's back, so insert it in odds
          else {
            evens.push_back(nums[i]);
            prev = 1;
          }
        }
      }
    
      // we can pop on last element from even, if size ar equal
      if(odds.size() == evens.size()) odds.pop_back();
    
      // alternatively add odd and subtract even elements
      while(evens.size()){
        ans += evens.front();
        evens.pop_front();
        
        if(odds.size()){
          ans -= odds.front();
          odds.pop_front();
        }
        
      }
      
      return ans;
    }
};
