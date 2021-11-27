class Solution {
public:
    

vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string local;
        vector<vector<char>> table{{'0'}, {'1'}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        
        backtracking(table, res, local, 0, digits);
        return res;
    }
    
    void backtracking(vector<vector<char>>& table, vector<string>& res, string& local, int index, string& digits){
        int digit = digits[index] - '0';

        if(index == digits.size())
            res.push_back(local);
        else
            for(int i = 0; i < table[digit].size(); i++){
                local.push_back(table[digit][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
    }

};