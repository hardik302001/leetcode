// https://leetcode.com/problems/daily-temperatures/submissions/
// https://leetcode.com/problems/online-stock-span/

/* MOST IMPO QUESTION */ 
//https://leetcode.com/problems/sum-of-subarray-ranges/



// see this for front traversal :  https://leetcode.com/submissions/detail/504849684/
// or the first python solution


/*
front traversal
decreasing monotonic stack, lead coding by fraz youtube(montonic stack 16 mins video)
map update before popping

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
        map<int,int>m1; 
        stack<int>st;
        int n=nums2.size();
        //reverse traversal...
          for(int i=0;i<n;i++){

              while(!st.empty() && st.top()<=nums2[i]){    //less than equal consider is must! in both nge-i and nge-ii   
                  m1[st.top()] = nums2[i];
                  st.pop();
              }

              st.push(nums2[i]);
          }
        
        while(!st.empty()){
            m1[st.top()] = -1;
            st.pop();
        }
        vector<int>ans;

        for(auto i:nums1){
            ans.push_back(m1[i]);
        }


        return ans;
    }
};




/* 
reverse traversal, takeuforward ki approach..
map me update before pushing in stack

*/
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
//         map<int,int>m1; 
//         stack<int>st;
//         int n=nums2.size();
//         //reverse traversal...
//           for(int i=n-1;i>=0;i--){

//               while(!st.empty() && st.top()<=nums2[i]){    //less than equal consider is must! in both nge-i and nge-ii       
//                   st.pop();
//               }

//               if(st.empty()){
//                   m1[nums2[i]]=-1;
//               }

//               else{
//                   m1[nums2[i]]=st.top();   //we are updating nge before putting it inside stack!
//               }

//               st.push(nums2[i]);


//           }
//         vector<int>ans;

//         for(auto i:nums1){
//             ans.push_back(m1[i]);
//         }


//         return ans;
//     }
// };


