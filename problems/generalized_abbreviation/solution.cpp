class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> solution;
        string cur = "";
        compute(word, 0, cur, solution);
        return solution;
    }

    void compute(const string& word, int start, string& cur, vector<string>& solution) {
        if (start == word.size()) {
            solution.push_back(cur);
            return;
        }

        cur.push_back(word[start]);
        compute(word, start + 1, cur, solution);
        cur.pop_back();

        int cur_size = cur.size();
        for (int i = start; i < word.size(); i++) {
            int length = i + 1 - start;
            cur.append(to_string(length));
            if (i + 1 < word.size()) {
                cur.push_back(word[i + 1]);
                compute(word, i + 2, cur, solution);
                cur.pop_back();
            } else {
                solution.push_back(cur);
            }
            cur.resize(cur_size);  // reset to original state
        }
    }
};