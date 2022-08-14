#define len(v) (int)((v).size())
#define ALL(v) v.begin(),v.end()
class Solution {
public:
    // distToEnd[i] = distance from i to "endWord"
    map<string,int> distToEnd;

    template <typename T>
    map<T,int> buildShortestDists(const T& start, const map<T,vector<T>>& G) {
        map<T,int> res;
        queue<pair<T,int>> q; q.push({start, 0});
        while (!q.empty()) {
            pair<T,int> pop = q.front(); q.pop();
            if (res.count(pop.first)) continue;
            res[pop.first] = pop.second;
            for (const T& neibor : G.at(pop.first))
                q.push({neibor, pop.second+1});
        }
        return res;
    }

    void dfs(const map<string,vector<string>>& G, const string& end, const int& maxAllowedDist,
        vector<string>& curPath, set<string>& seen, vector<vector<string>>& res) {
        if (len(curPath)-1 == maxAllowedDist) {
            if (curPath.back() == end)
                res.push_back(curPath);
            return;
        }

        for (const string& neibor : G.at(curPath.back())) {
            // this optimization is key to AC
            if (distToEnd[neibor] + len(curPath) != maxAllowedDist) continue;
            if (seen.count(neibor)) continue;

            curPath.push_back(neibor);
            seen.insert(neibor);
            dfs(G, end, maxAllowedDist, curPath, seen, res);
            curPath.pop_back();
            seen.erase(neibor);
        }
    }

    bool existEdge(const string& a, const string& b) {
        int differentChars = 0;
        for (int i = 0; i < len(a); i++)
            differentChars += a[i] != b[i];
        return differentChars == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (count(ALL(wordList), endWord) == 0) return {};
        map<string, vector<string>> G; G[beginWord];
        for (int i = 0; i < len(wordList); i++) {
            G[wordList[i]];
            for (int j = i+1; j < len(wordList); j++) {
                if (existEdge(wordList[i], wordList[j])) {
                    G[wordList[i]].push_back(wordList[j]);
                    G[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        if (count(ALL(wordList), beginWord) == 0) {
            for (const string& word : wordList)
                if (existEdge(beginWord, word))
                    G[beginWord].push_back(word);
        }

        int maxAllowedDist = (buildShortestDists(beginWord, G))[endWord];
        if (maxAllowedDist == 0) return {};
        this->distToEnd = buildShortestDists(endWord, G);

        vector<string> curPath = {beginWord};
        set<string> seen; seen.insert(beginWord);
        vector<vector<string>> res;
        dfs(G, endWord, maxAllowedDist, curPath, seen, res);
        return res;
    }
};