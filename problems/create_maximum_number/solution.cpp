// Basic Idea of this problem is that we have two arrays, so we find the largest 'i' digit number from nums1 and largest 'k-i' digit number from nums2.
// as we did in https://leetcode.com/problems/find-the-most-competitive-subsequence/submissions/

//After having these two, we merge them using merge sort algorithm. We use merge sort because it can be proved that largest number will always be sorted in descending order. The only thing to keep in mind while merging is the case where array elements are equal. In that case, we have to loop untill we find a greater element in one of the two arrays and then act accordingly.
// So after finding a i digit number from nums1 and k-i digit number from nums2, we merge them to form the maximum k digit number from these two arrays.

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <int>res;

        for(int i = 0; i<=k; i++){
            if(nums1.size()<i or nums2.size()<(k-i)) continue;
            vector <int> a = fun(nums1, i);
            vector <int> b = fun(nums2, k-i);

            vector <int> m;
            merge(a, b, m);
            // for(auto x: a) cout<<x<<" ";
            // cout<<endl;
            // for(auto x: b) cout<<x<<" ";
            // cout<<endl;
            // for(auto x: m) cout<<x<<" ";
            // cout<<endl;
            // cout<<"-----------------\n";

            if(m.size()==k) res = max(res,m);
        }
        return res;
    }

    // This function is the similar to code of "Find most consecutive subsequence" problem, which finds the k digit maximum number possible
    // just change sign of comparsion , here we need maximum
    
    vector <int> fun(vector <int>&nums, int k){
        int n = nums.size();
        int remove = (n-k);
        stack<int> st;
        for (auto &it : nums ){
            while(!st.empty() and remove and st.top() < it ){
                st.pop();
                remove--;
            }
            st.push(it);
        }

        while(remove--){
            st.pop();
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
    void merge(vector <int>&a, vector <int>&b, vector <int>&res){
        int i = 0, j = 0, k = 0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                int ti = i, tj = j;
                while(ti<a.size() and tj<b.size() and a[ti]==b[tj]) ti++, tj++;

                if(tj==b.size())      res.push_back(a[i]), i++;
                else if(ti==a.size()) res.push_back(b[j]), j++; 
                else if(a[ti]>b[tj])  res.push_back(a[i]), i++;
                else                  res.push_back(b[j]), j++;
            }
            else if(a[i]>b[j]) res.push_back(a[i]), i++;
            else res.push_back(b[j]), j++;
        }
        while(i<a.size()) res.push_back(a[i]), i++;
        while(j<b.size()) res.push_back(b[j]), j++;
    }
};