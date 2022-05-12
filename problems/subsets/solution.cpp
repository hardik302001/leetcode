//bitmanipulation

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size(), p = 1 << n;
//         vector<vector<int>> subs(p);
//         for (int i = 0; i < p; i++) {
//             for (int j = 0; j < n; j++) {
//                 if ((i) & (1<<j)) {
//                     subs[i].push_back(nums[j]);
                    
//                 }
//             }
//         }
//         return subs;
//     }
// };

/*
Time complexity: O(n * 2^N)  to generate all subsets and then copy them into output list.

Space complexity:  O(n * 2^N) to keep all the subsets of length NN, since each of NN elements could be present or absent.
*/

// ---------------------------------------------------------------------------------------------------

// Iterative

// Using [1, 2, 3] as an example, the iterative process is like:

// Initially, one empty subset [[]]
// Adding 1 to []: [[], [1]];
// Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
// Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].

/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};
*/

/*
Time complexity: O(n * 2^N)  to generate all subsets and then copy them into output list.

Space complexity:  O(n * 2^N) to keep all the subsets of length NN, since each of NN elements could be present or absent.
*/


// ---------------------------------------------------------------------------------------------------

// Recursive : backtracking

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
		sort(nums.begin(), nums.end());
        vector< vector<int> > res;
		vector<int> vec;
		subsets(res, nums, vec, 0);
		return res;
    }
private:
	void subsets(vector<vector<int> > &res, vector<int> &nums, vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i < nums.size(); ++i) {
			vec.push_back(nums[i]);
			subsets(res, nums, vec, i + 1);
			vec.pop_back();
		}
	}
};