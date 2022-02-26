class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target(num);
        for (int i = 0; i < k; ++i)
            next_permutation(target.begin(), target.end());
        
        cout<<target<<endl;
        int res = 0, n = num.size();
        for (int i = 0; i < n; ++i) {
            if (num[i] != target[i]) {
                int j = i + 1;
                while (num[j] != target[i])
                    j++;
                while(j > i)
                    swap(num[j], num[j - 1]), res++, j--;
            }
        }
        return res;
    }
};



// same logic , better code \U0001f446
/*
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string ans;
        string oldnum = num;
        while(k-- and next_permutation(num.begin(), num.end())){
            ans = num;
        }
        
        
        // https://www.geeksforgeeks.org/minimum-number-of-adjacent-swaps-to-convert-a-string-into-its-given-anagram/#:~:text=Minimum%204%20swaps%20are%20required.
        int size = num.size();
        int i = 0, j = 0;
        int result = 0;

        // Iterate over the first string and convert
        // every element equal to the second string
        while (i < size) {
            j = i;

            // Find index element of first string which
            // is equal to the ith element of second string
            while (ans[j] != oldnum[i]) {
                j += 1;
            }

            // Swap adjacent elements in first string so
            // that element at ith position becomes equal
            while (i < j) {

                // Swap elements using temporary variable
                char temp = ans[j];
                ans[j] = ans[j - 1];
                ans[j - 1] = temp;
                j -= 1;
                result += 1;
            }
            i += 1;
        }
        return result;

        
    }
};

*/