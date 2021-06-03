//COURTESY: CODINGMINUTES..
//QUICKSELECT :KTH SMALLEST
//BUT HERE kth largest..so n-k smallest in reversed!!
//thats all we did



class Solution {
public:
    int partition(vector<int>& a,int s,int e){
        int pivot = a[e];
        int i = s-1;
        for (int j = s;j<e;j++){
            if(a[j]<=pivot){
                i++;
                swap(a[i],a[j]);
            }
        }
        
        swap(a[i+1],a[e]);
        return i+1;
    }  //standard partition functio 
    
    int findKthLargest(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;
        int c = (e + 1) - k;              //kth smallest here in n-k in reversed
        while(1){
            //rather than going recursive we went for while 1 ..bcz we did not had s and e as parameters in actual function findKthLargest
            
            //and only thing varying was also s and e
            
            int p = partition(nums,s,e);
            cout<<p<<endl;
            if(p==c){
                return nums[p];
            }
            else if(c<p){
                e = p - 1;
            }
            else{
                s = p + 1;
            }
            
            
            //rest all is standard and same
            
        }
    }
};