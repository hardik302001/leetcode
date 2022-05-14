class Solution {
    public:
        int largestVariance(string s) {
            return maxDeviation(s);
        }

    int modifiedKadane(vector < int > & arr, int k) {
        if (arr.size() < k)
            return 0;

        int n = arr.size();
        vector < int > maxSum(n);

        // use kadane's
        maxSum[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxSum[i] = max(arr[i], maxSum[i - 1] + arr[i]);
        }

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int ans = sum;
        for (int i = k; i < arr.size(); i++) {
            sum = sum + arr[i] - arr[i - k];
            ans = max(ans, sum);
            ans = max(ans, sum + maxSum[i - k]);
        }

        return ans;
    }

    int maxDeviation(string str) {
        int ans = 0;

        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                if (c1 == c2)
                    continue;

                vector < int > arr;
                // we consider c1 as character with maxFreq and c2 with minFreq
                for (auto c: str) {
                    if (c == c1) {
                        // We shall include all consecutive c1's in our array so we add their frequency
                        if (arr.size() && arr.back() != -1) {
                            arr.back() += 1;
                        } else {
                            arr.push_back(1);
                        }
                    } else if (c == c2) {
                        // we take distinct c2
                        arr.push_back(-1);
                    }
                }
                ans = max(ans, modifiedKadane(arr, 2));
            }
        }
        return ans;
    }
};