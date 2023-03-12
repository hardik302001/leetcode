class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> keyIndices(26, -1);

        // Get the index for each key.
        for (int i = 0; i < keyboard.length(); i++)
            keyIndices[keyboard[i] - 'a'] = i;

        // Initialize previous index as starting index = 0.
        int prev = 0;
        int result = 0;

        // Calculate the total time.
        for (char &c : word) {
            // Add the distance from previous index
            // to current letter's index to the result.
            result += abs(prev - keyIndices[c - 'a']);

            // Update the previous index to current index for next iteration.
            prev = keyIndices[c - 'a'];
        }
        return result;
    }
};