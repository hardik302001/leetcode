class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& arr, vector<vector<int>>& queries) {
            // Accumulate the entire sum
        int sum = 0;
        for(auto ele:arr)
            if(ele%2==0) sum +=ele;

        // Vector to store the answer of each query
        vector<int> answer;

        // Traverse the query and update the sum
        for(auto row_vec:queries)
        {
            // Get the value to be added and the index which is modified
            int extra = row_vec[0];
            int index = row_vec[1];

            // If it was included, then just remove it for now
            if(arr[index]%2==0) sum -= arr[index];

            // Update the array and check whether we should include it now
            arr[index] +=extra;
            if(arr[index] %2 ==0) sum+=arr[index];

            // Update the sum
            answer.push_back(sum);
        }

        // Return the stored answer;
        return answer;
    }
};