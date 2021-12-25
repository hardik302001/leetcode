//MEMOSIZED RECURSION
//DP VARIANT
//IMPO QUES
//There are many repeating subquestions in this recursive method, therefore, we could use dynamic programming to avoid this situation by saving the results for subquestions. Here is the DP solution.

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dpMap;
		return computeWithDP(input, dpMap);
	}

	vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
		vector<int> result;
		int size = input.size();
		for (int i = 0; i < size; i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				// Split input string into two parts and solve them recursively
				vector<int> result1, result2;
                
                
				string substr1 = input.substr(0, i);
				// check if dpMap has the result for substr
				if (dpMap.find(substr1) != dpMap.end())
					result1 = dpMap[substr1];
				else
					result1 = computeWithDP(substr1, dpMap);

                
                
                
				string substr2 = input.substr(i + 1,size);
				if (dpMap.find(substr2) != dpMap.end())
					result2 = dpMap[substr2];
				else
					result2 = computeWithDP(substr2, dpMap);
				
				for (auto n1 : result1) {
					for (auto n2 : result2) {
						if (cur == '+')
							result.push_back(n1 + n2);
						else if (cur == '-')
							result.push_back(n1 - n2);
						else
							result.push_back(n1 * n2);
					}
				}
			}
		}
		// if the input string contains only number
		if (result.empty())
			result.push_back(stoi(input));
		// save to dpMap
        
		dpMap[input] = result;
		return result;
	}
};







/*

//RECURSIVE CODE!
//DIVIDE AND CONQUER
//see the beauty of code, we are returning the res vector evry time, going in deep and returning back output..
//can be optimised using memosization!

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1,size));
                
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(stoi(input));
        return result;
    }
};

*/