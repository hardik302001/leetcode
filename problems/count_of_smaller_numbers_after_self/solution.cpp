// we cant use monotonic stack here counter case [2,0,1] , i tried doing nse

// also see this solution , other way of doing things: https://leetcode.com/submissions/detail/703847747/


// first see it, then come here..|
//                              \|/
// also see: https://leetcode.com/problems/reverse-pairs/


// see striver video, inversion count , reverse pairs

/*
 
COUNT INVERSIONS , for every index i
thats why we did vector of pair, bcz we need to give answer for each index, and after sorting indexes will interchange , so we need to keep index intact with value

*/
class Solution {
public:
    
    void merge(vector<pair<int, int>>&vp , int start , int mid , int end , vector<int>&ans){
        
        // CALCULATING 
        int j = mid+1;
        int i;
        
        // rememeber both left and right partition are sorted
        // so try to visualise yourself ,how to find count for every i in left partition such that nums[i] > nums[j] in right partition , and both partition are sorted...
        // we traverse and count for each i , uptil when nums[i]>nums[j] and upadte j, when this condition breaks , it means we dont have more j such that nums[i]>nums[j] , bcz right partition is sorted..
        
         
        for(i = start;i<=mid;i++){
            while(j<=end and vp[i].first>vp[j].first){
                j++;
            }
            ans[vp[i].second] += (j-(mid+1));
        }
                
                
        // ----------------- doing the merge sort part ---------------------
        vector<pair<int, int>>temp(end-start+1);     // to join the 2 sorted partitions
        i = start; // start of left partition
        j = mid+1; // start of right partition
        int k = 0; // index for combined sorted partition
        while(i<=mid and j<=end){
            if(vp[i].first>vp[j].first){
                temp[k] = vp[j];
                k+=1;
                j+=1;
            }else{
                temp[k] = vp[i];
                k+=1;
                i+=1;
            }
        }
        
        // now adding remaining elements to our sorted temp..
        
        // for (i<= mid) bcz all the remaining i are obv greater than all right partition elements 
        // so we add size of right partition to our ans[vp[i].second]
        // now j = end+1
        
        while(i<=mid) temp[k++] = vp[i++]; 
        while(j<=end) temp[k++] = vp[j++];
        
        
        
        // now we update our value-pair(vp) to temp, why because we will pass vp for our next recursion only..
        i = start;
        k = 0;
        while(i <= end){
            vp[i++] = temp[k++];
        }
    }
    
    void mergesort(vector<pair<int , int>>&vp, int l , int r, vector<int>&ans){
        if(l<r){
            int m = (l+r)/2;
            mergesort(vp, l , m, ans);
            mergesort(vp , m+1 , r, ans);
            merge(vp, l ,m , r, ans);   // rememeber (l , m, r)
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        
        vector<pair<int , int>>vp; // bcz after sorting the indexes will be changed , so to track it
        for(int i = 0;i<n;i++){
            vp.push_back({nums[i], i});
        }
        
        mergesort(vp, 0 , n-1, ans);  // rememeber 0 to (n-1)
        
        return ans;
    }
};