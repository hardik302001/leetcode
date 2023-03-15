class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        size_t n = s.length();
        if (n * k == 0) {
            return 0;
        }
        int left = 0, right = 0;
        map<char, int> rightmost_position;

        int max_length = 1;

        while (right < n) {
            rightmost_position[s[right]] = right;
            right++;

            if (rightmost_position.size() == k + 1) {
                int lowest_index = INT_MAX;
                for (pair<char, int> element : rightmost_position) {
                    lowest_index = min(lowest_index, element.second);
                }
                rightmost_position.erase(s[lowest_index]);
                left = lowest_index + 1;
            }

            max_length = max(max_length, right - left);
        }
        return max_length;
    }
};