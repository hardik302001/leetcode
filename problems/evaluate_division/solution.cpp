//  ALSO VISIT HERE: FOR DSU APPROACH! (makung ckasses and then calling meod by making objects)
// https://leetcode.com/problems/evaluate-division/discuss/1142350/c%2B%2B-Simple-Union-Find-Approach-(creates-union-find-class)

class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> children;                               // adjacency list
    
    pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);                                                                  // mark a as visited
            for (auto p : children[a]) {
                double temp = val * p.second;                                                   // potential result
                if (p.first == b) { return make_pair(true, temp); }                             // found result
                
                auto result = search(p.first, b, visited, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> ans;
        
        for (int i = 0; i < equations.size(); i++) {
            children[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));      // build graph list a->b
            children[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));// build graph list b->a
        }
        
        for (auto p : queries) {
            unordered_set<string> visited;                                                          // to record visited nodes
            // p.first == p.second is special case
            ans.push_back(p[0] == p[1] && children.count(p[0]) ? 1.0 : search(p[0], p[1], visited, 1.0).second);
        }
        
        return ans;
    }
};