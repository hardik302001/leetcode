class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1){return arr[0];}
        
        vector<int> fw(n,0);
        vector<int> bw(n,0);
        int cur_max=arr[0],max_so_far=arr[0];
        fw[0]=arr[0];
        for(int i=1;i<n;i++){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            fw[i]=cur_max;
        }
        cur_max=max_so_far=bw[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            bw[i]=cur_max;
        }
        int res=max(fw[n-2], bw[1]);   //if we delete first or last element
        res = max(res, max_so_far);   // if we do not delete any element
        for(int i=1;i<n-1;i++)
            res=max(res,fw[i-1]+bw[i+1]);
        return res;
    }
};