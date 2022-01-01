class OrderedStream {
public:
    int p;
    vector<string>q;

    OrderedStream(int n) {
        q.resize(n,"");
        p = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string>ans;
        q[id-1] = value;

        if(id==p){
            while (p<=q.size() and q[p-1]!=""){
                ans.push_back(q[p-1]);
                p= p+1;
            }
        }
        // cout<<p<<endl;
        return ans;
        
    }
};


