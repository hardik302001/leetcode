//you can even do it using map,, see prev PYTHON CODE


//trie is better
//no collision
//no space issue






class TrieNode{
public:
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        //build trie
        TrieNode* root = new TrieNode;          
        /*
        //here no constructor, so we declare it liek object..
        //if there was some constructor like below, so instantiate it like this 
        
                Trie() {
                    root = new TrieNode();
                }
                
                private:
                    TrieNode root;    
        
        */
        
        
        /* INSERT FUNCTION  */ 
        for(string word:dict){
            TrieNode* cur = root;
            for(char c : word){
                if(cur->children[c-'a'] == NULL) cur->children[c-'a'] = new TrieNode;
                cur = cur->children[c-'a'];
            }
            cur->end = true;
        }
        
        //generate res
        string res, token;
        stringstream iss(sentence);
        while(getline(iss, token,' '))       
            res+=helper(token,root)+" ";
        res.pop_back();
        
        clear(root);                          //deallocate memory  ...dstructor
        return res;
        
    }
    
    
    string helper(string word, TrieNode* root){
        TrieNode* t = root;
        for(int i=0;i<word.length();i++){
            if(t->end)  return word.substr(0,i);  //shortest length prefix
            if(t->children[word[i]-'a'])    t=t->children[word[i]-'a'];    //we have path...so follow it
            else   return word;                                            //the word is longest than possible inserted strings, so no choices to return word
        }
        return word;     //after all combinations, we are out, so return word
    }
    
    
    
    
    void clear(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i])   clear(root->children[i]);
        }
        delete root;
    }
    
    
    
};