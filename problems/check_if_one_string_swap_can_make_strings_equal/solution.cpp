class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        // find the number of diff positions
        vector<int> diff_pos;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                diff_pos.emplace_back(i);
        }
        // when the chars are exactly the same
        if(diff_pos.empty())
            return true;
        // only one pair of diff positions, check if swapping makes them equal
        if(diff_pos.size() == 2) 
            swap(s1[diff_pos[0]], s1[diff_pos[1]]);
        
        return s1 == s2;
    }
};
