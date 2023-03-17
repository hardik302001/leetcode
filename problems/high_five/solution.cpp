class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        map<int, priority_queue<int>> allScores;
        for (const auto &item: items) {
            int id = item[0];
            int score = item[1];
            // Add score to the max heap
            allScores[id].push(score);
        }
        vector<vector<int>> solution;
        for (auto &[id, scores] : allScores) {
            int sum = 0;
            // obtain the top k scores (k = 5)
            for (int i = 0; i < this->K; ++i) {
                sum += scores.top();
                scores.pop();
            }
            solution.push_back({id, sum / this->K});
        }
        return solution;
    }
};