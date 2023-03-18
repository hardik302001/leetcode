// logic idea from : https://www.tutorialcup.com/leetcode-solutions/alien-dictionary-leetcode-solution.htm
// here we need smallest lexo string as output
// There may be multiple valid order of letters, return the smallest in normal lexicographical order.

// but in actual leetcode ques, we can return any of the string
class Solution {
public:
    int flag = 1;  // that we cant make graph, bcz of conflicts
    
    string alienOrder(vector<string> &words) {
        map<char, set<char> > graph = buildGraph(words);
        if (flag==0) return "";   
        return topoSort(graph);
    }
    
    map<char, set<char> > buildGraph(vector<string> &words) {
        
        map<char, set<char> > graph;
        
        //create nodes for each of the char
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                if (graph.count(c) == 0) {
                    graph[c] = set<char>();
                }
            }
        }
        
        // create edges
        for(int w = 0; w < words.size()-1; w++) {
            int common_len = min(words[w].size(), words[w+1].size());
            // check if the lexographic order is being followed or not
            // P.S I dont think this case is even valid acc to problem description
            // Eg: ["abc", "ab"] -> Invalid
            if(words[w+1].size() < words[w].size()  and words[w].substr(0, common_len) == words[w+1])
                flag = 0;
            
            for(int i = 0; i < common_len; i++) {
                // prevent self loop
                char src = words[w][i], dst = words[w+1][i];
                // If current pos has diff chars, then make an edge and
                // break since, the current word ordering was due this positional char
                // change and anything beyond this might not follow actual order.
                if(src != dst) {
                    graph[src].insert(dst);
                    break;
                }
            }
        }
        
        return graph;
    }
    
    string topoSort(map<char, set<char> >& graph) {
        
        map<char, int> indegree = getIndegree(graph);
        priority_queue<char, vector<char>, greater<char> > queue; // min pq, for smallest charcter at beginning
        
        for (auto p : indegree) {
            if (p.second == 0) {
                queue.push(p.first);
            }
        }

        string res;
        while (queue.empty() == false) {
            char c = queue.top();
            queue.pop();
            res += c;
            for (auto& ch : graph[c]) {
                indegree[ch]--;
                if (indegree[ch] == 0) {
                    queue.push(ch);
                }
            }
        }
        // indegree will contains total number of nodes.. so we want all nodes in res
        return (res.size() != indegree.size()) ? "" : res;
    }
    
    map<char, int> getIndegree(map<char, set<char> >& graph) {
        map<char, int> indegree;

        // initialise all nodes
        for (auto& p : graph) {
            indegree[p.first] = 0;
        }
        // update degree
        for (auto& p : graph) {
            for (char c : p.second) {
                indegree[c]++;
            }
        }
        return indegree;
    }
};