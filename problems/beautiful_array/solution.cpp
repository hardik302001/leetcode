/*Different with the most voted solution, I generate the permutaion in the begining.

int S* = {1,2,3,4,5,6,7,8}
Obviously, it's not a beautiful array, let's make it a beautiful one.
My intuition is: sifting all possible A[k] out until it's beautiful.

I extract the elements with even index(i.e. 0,2,4...) to the front of subarray while the odd to the back of subarray. Like

int A* = {1,3,5,7};
int B* = {2,4,6,8};
//update S
S= {1,3,5,7,2,4,6,8};
But in subarray itself, it's still not beautiful, let's look at left subarray.

int * A = {1,3,5,7} 
2*A[1] = A[0] * A[2]; //broke the rule
So let's do the same thing for this subarray, move elements with even index forward, while the odd backward.

//update A
A = {1,5,3,7}
Keep dividing until the array size <= 2, then all the possible A[k] are separted with A[i], A[j].
//Talk is cheap, here is the code:)

*/
   










class Solution {
public:
     vector<int> beautifulArray(int N) {
        vector<int> S;
        for (int i = 1; i <= N; ++i) {
            S.push_back(i);
        }
        divide(S, 0, N - 1);
        return S;
    }
    
    void divide(vector<int>& S, int l, int r) {
        if (r <= l) return;
        vector<int> odd, even;
        for (int i = l; i <= r; ++i) {
            if ((i + 1 - l) & 1) { //using relative index(because S have 0 based indexing)
                odd.push_back(S[i]);
            } else {
                even.push_back(S[i]);
            }
        }
        std::copy(odd.begin(), odd.end(), S.begin() + l);
        std::copy(even.begin(), even.end(), S.begin() + l + odd.size());
        int m = (r - l) / 2 + l;
        divide(S, l, m);
        divide(S, m + 1, r);
    }

};