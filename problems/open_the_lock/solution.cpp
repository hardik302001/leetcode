//BFS

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        int result = 0;
        if (deadendsSet.find("0000") != deadendsSet.end()) {
            return -1;
        }
        queue<string> wheelQueue;
        wheelQueue.push("0000");
        visited.insert("0000");
        while (!wheelQueue.empty()) {
            int levelSize = wheelQueue.size();
            while (levelSize--) {
                string up;
                string down;
                string currentWheel = wheelQueue.front();        // 3 cases
                wheelQueue.pop();
                if (currentWheel == target) { //curr wheel
                    return result;
                }
                
                //now 2 cases for up and down

            
                for (int i = 0; i < 4; i++) {
                    // every time,we can change atmost one wheel, fro up and down, and get a new combination, so we always reset up and down to curr!
                    down = currentWheel;
                    up = currentWheel;
                    char upCh = up[i], downCh = down[i];
                    up[i] = (upCh == '9' ? '0' : upCh + 1);
                    down[i] = (downCh == '0' ? '9' : downCh - 1);
                    if (visited.find(up) == visited.end() && deadendsSet.find(up) == deadendsSet.end()) {
                        wheelQueue.push(up);
                        visited.insert(up);
                    }
                    if (visited.find(down) == visited.end() && deadendsSet.find(down) == deadendsSet.end()) {
                        wheelQueue.push(down);
                        visited.insert(down);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};