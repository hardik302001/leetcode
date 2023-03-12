class Solution {
public:
    int largestUniqueNumber(vector<int> &A) {
        unordered_map<int, int> count;
        // Store counts of each element
        for (int &i : A) {
          count[i]++;
        }
        int result = -1;
        for (auto &[key, val] : count) {
            // If count of the integer is 1, get maximum.
            if (val == 1) {
              result = max(result, key);
            }
        }
        return result;
    }
};