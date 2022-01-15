// greedy

class Solution{
public: 
    bool canJump(vector<int>& nums){
        int n = nums.size();
        int canreach = 0;
        
        for(int i = 0;i<n;i++){
            if(i>canreach){
                return false;
            }
            canreach = max(canreach , i + nums[i]);
        }
        
        return true;
        
    }   
};



// // brute force

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> jump(n,false);
//         jump[n-1]=true;
        
//         for(int i=n-2;i>=0;i--)
//         {
//             for(int j=0;j<=nums[i] && j<n;j++)
//             {
//                 if(jump[i+j]==true)     
//                 {
//                     jump[i]=true; 
//                     break;
//                 }
//             }
//         }

//         return jump[0];
//     }
// };