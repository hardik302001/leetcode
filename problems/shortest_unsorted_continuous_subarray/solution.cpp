class Solution {
public:
    
    bool outOfOrder(vector<int> arr,int i){
        int x = arr[i];
        if(i==0){
            return x > arr[1];
        }
        if(i==arr.size()-1){
            return x < arr[i-1];
        }
        return x > arr[i+1] or x < arr[i-1];

    }


    int findUnsortedSubarray(vector<int>& arr){

        int smallest = 1000000;
        int largest = -1000000;
        if(arr.size()==1){return 0;}
        for(int i=0;i<arr.size();i++){
            int x = arr[i];

            if(outOfOrder(arr,i)){
                smallest = min(smallest,x);
                largest = max(largest,x);
            }
        }

        cout<<smallest<<largest<<endl;
        //next step find the right index where smallest and largest lie (subarray) for our solution
        if(smallest==1000000 or largest ==-1000000){
            return 0;
        }

        int left = 0;
        while(smallest >= arr[left]){    // leftmost occurence of element greater than smallest
            left++;
        }
        int right = arr.size() - 1;
        while(largest <= arr[right]){    // rightmost occurence of element smaller than largest
            right--;
        }
        
        // cout<<smallest<<" "<<largest<<" "<<left<<" "<<right<<endl;
        
        return right-left+1;

    }

};