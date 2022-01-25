/*
Of course, from the perspective of a self-taught coder with no theoretical background, here is my very intuitive process:

Intuition: the problem is trivial with just brute force. Since there are only 8 rows, it is intuitive to think about a cycle.
Noticed that first and last cells will turn 0 after the first round. This is the only case where the original is not part of the cycle.
I cannot prove that a cycle exist, but I did tried a case with 4 columns and not hard to see that it is a complete cycle other than the case mentioned above. If you communicate with interviewer well, you will know that you are on the right track.


See for this question, it is very easy to come up with a brute force solution. You use two for loops. Now you ask the interviewer, do i need to optimize this? If he says yes, then it means you need to do it in less than 6N.
What is less than 6N? So if someway you could find a cycle to skips a few Ns like N=N+14 in this case, you can optimize the complexity.
Here is the brute force I am taking about.

*/

// brute force
// TC: O(6N)
// class Solution{
// public:
//     vector<int> prisonAfterNDays(vector<int>& cells, int N) {
//         vector<int> ans(8,0);
//         for(int i=0;i<8;i++){
//             ans[i]=cells[i];
//         }
//         cells[0]=0;
//         cells[7]=0;
//         for(int i=1;i<=N;i++){
//             int j=1;
//             while(j<7){
//                 if((ans[j-1]==0 && ans[j+1]==0) || (ans[j-1]==1 && ans[j+1]==1)){
//                     cells[j]=1;

//                 }
//                 else{
//                     cells[j]=0;
//                 }
//                 j++;
//             }
//             for(int i=0;i<8;i++){
//                 ans[i]=cells[i];
//             }
            
//             for(auto i: ans){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }
//         // for(int i=0;i<8;i++){
//         //     ans[i]=cells[i];
//         // }
//         return ans;
//     }
// };


class Solution{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> ans(8,0);
        for(int i=0;i<8;i++){
            ans[i]=cells[i];
        }
        cells[0]=0;
        cells[7]=0;
        
        vector<vector<int>>res;
        for(int i=1;i<=14;i++){
            int j=1;
            while(j<7){
                if((ans[j-1]==0 && ans[j+1]==0) || (ans[j-1]==1 && ans[j+1]==1)){
                    cells[j]=1;

                }
                else{
                    cells[j]=0;
                }
                j++;
            }
            for(int i=0;i<8;i++){
                ans[i]=cells[i];
            }
            
            res.push_back(ans);
        }
        int ind = (n-1)%14;
        vector<int>final = res[ind];
        
        return final;
        
    }
};