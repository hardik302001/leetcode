class UnionFind {
public:  
    vector<int> parent;
    int count = 0;
    UnionFind(int n){                  //constructor
        count = n;
        parent = vector<int>(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] =  find(parent[x]);
    }

    void Union(int x,int y){
        int X = find(x);
        int Y = find(y);

        if(X==Y) return;
        if(X<Y) swap(X, Y);   // always the small one
        parent[X]=Y;
        count--;
    }

    int getCount(){
        return count;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

};

    
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        int sz = s1.size();
        for(int i = 0;i<sz;i++){
            int a = s1[i]-'a';
            int b = s2[i]-'a';
            uf.Union(a, b);
        }
        
        string ans;
        vector<int>p = uf.parent;

        for(auto x: baseStr){
            ans += char(uf.find(x-'a')+'a');
        }
        
        
        return ans;
    }
};