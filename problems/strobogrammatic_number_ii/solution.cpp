// Time complexity: O(5^n). // we have 5 options for each position in n.
// Space complexity: O(5) // recursive stack for the length of number of pairs

class Solution {
    vector<string> result;
    unordered_map<char, char> validnums;
public:
    vector<string> findStrobogrammatic(int n) {
        validnums = {{'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}, {'0', '0'}};
        string output(n, '0');
        dfs(0, n - 1, output);
        return result;
    }
    
    void dfs(int left, int right, string output) {
        if(left > right) {
            result.push_back(output);
            return;
        }
        for(auto each : validnums) {
            output[left] = each.first;
            output[right] = each.second;
            if(output.size() != 1 && output[0] == '0')
                continue;
            if(left < right || (left == right && each.first == each.second))
                dfs(left + 1, right - 1, output);
        }
    }
};