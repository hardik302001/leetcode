/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// BFS
/*

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;                  // map , decalred in private scope
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            for (Node* neighbor : cur -> neighbors) {
            
            
            // like i do in python while addding to dict
                if (copies.find(neighbor) == copies.end()) {              // if not visited, make a copy for it, ad to queue
                    copies[neighbor] = new Node(neighbor -> val, {});
                    todo.push(neighbor);
                }

		// now we have node for neighbour, time to add this neighbour to neighbours of or=ur current node.
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;    // to keep track that every node have its copy 
};

*/

// DFS
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        // for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        // Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph
        
    }
};