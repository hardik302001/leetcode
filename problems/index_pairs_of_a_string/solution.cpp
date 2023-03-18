// trie

class Solution {
public:
    struct Node
    {
        vector<Node*>children;
        bool isEnd;
        Node()
        {
            children=vector<Node*>(26,NULL);
            isEnd=false;
        }
    };
    void insert(Node *root,string word)
    {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(temp->children[index]==NULL)
            {
                temp->children[index]=new Node();
            }
            temp=temp->children[index];
        }
        temp->isEnd=true;
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words)
    {
        Node *root=new Node();
        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);
        }
        vector<vector<int>>res;
        for(int i=0;i<text.size();i++)
        {
            Node *temp=root;
            for(int j=i;j<text.size();j++)
            {
                temp=temp->children[text[j]-'a'];
                if(temp!=NULL&&temp->isEnd==true)
                    res.push_back({i,j});
                if(temp==NULL)
                    break;
            }
        }
        return res;
    }
};