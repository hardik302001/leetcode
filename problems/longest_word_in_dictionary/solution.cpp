class TrieNode {
public:
    TrieNode* children[26];
    bool end;
    
    TrieNode() {
        end = false;
        for(int i= 0 ;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        TrieNode *root = new TrieNode();
        for(string s: words) {
            insert(root, s);
        }
        
        string ans;
        for(string s: words) 
        {
            if(ans.size() > s.size()) continue;            
            if(search(root, s)) {
                if(ans.size() == s.size()) ans = min(s, ans);
                else ans = s;
            }
        }
        return ans;
    }
    
    void insert(TrieNode *root, string s)
    {
            TrieNode* cur = root;
            for(char c : s){
                if(cur->children[c-'a'] == NULL) cur->children[c-'a'] = new TrieNode;
                cur = cur->children[c-'a'];
            }
            cur->end = true;
    }
    
    bool search(TrieNode *root, string s)
    {
        int count = 0;
        TrieNode *curr = root;
        for(char c: s){
            int index = c - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                      //not even reached at end of the word
            }            
        

            if(curr->end) ++count;
        }
        return count == s.size();            //impo step, we are conisdering only those which have, prev one charxter cndition satisfied
    }
};