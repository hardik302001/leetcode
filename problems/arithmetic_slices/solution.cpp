/*
We find the sub problem:
Assume A[i:j] (both include A[i] and A[j]) is an arithmetic slice, then we have:

if A[i]-A[i-1] = = A[i+1]-A[i], then A[i-1:j] is an arithmetic slice;
if A[j+1]-A[j] = = A[j]-A[j-1], then A[i:j+1] is an arithmetic slice.
use dp[i][j] to memorize whether A[i:j] is an arithmetic slice, and count to count the num of arithmetic slices:


2nd DP Solution: time O(n), space O(n)
We can find another sub problem: assume dp[i] is the number of arithmetic slices which are end with A[i]. then we have:
dp[i]=(A[i]-A[i-1] = = A[i-1]-A[i-2])? 1+dp[i-1] : 0, the code:
*/


// class Solution{
// public:
//     int numberOfArithmeticSlices(vector<int>&A) {
//     int n=A.size();
//     if(n<3){return 0;}
//     vector<int>dp(n);
//     dp[0]=0;
//     dp[1]=0;
//     int sum=0;
//     for(int i=2;i<n;i++){
//         if((A[i]-A[i-1])==(A[i-1]-A[i-2])){
//             dp[i]=dp[i-1]+1;
//         }else{
//             dp[i]=0;
//         }
//         sum+=dp[i];
//     }
//     return sum;
// }
// };

// up to now, time complexity is O(n), but space complexity is also O(n). In fact, we only need a curr to memorize the num of arithmetic slices which end with current A[i] and a sum to memorize num of all curr. that is @icl7722's solution, which time complexity is O(n) and space complexity is O(1).


class Solution{
public:
    int numberOfArithmeticSlices(vector<int>& A) {
	int curr = 0, sum = 0;
	for (int i=2; i<A.size(); i++)
		if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
			curr += 1;
			sum += curr;
		} else {
			curr = 0;
		}
	return sum;
}
};