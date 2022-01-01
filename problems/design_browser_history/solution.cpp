class BrowserHistory {
public:
    stack<string> s;
    stack <string>q;
    BrowserHistory(string homepage) {
        s.push(homepage);
    }
    
    void visit(string url) {
        s.push(url);
        while(!q.empty()){
            q.pop();
        }
    }
    
    string back(int steps) {
        if(s.size()==1){
            return s.top();
        }
        else{
            while(steps-- and s.size()>1){
                string top = s.top();
                s.pop();
                q.push(top);
                
            }
            
            return s.top();
                
        }
        
    }
    
    string forward(int steps) {
        if(q.size()==0){
            return s.top();
        }
        else{
            while(steps-- and !q.empty()){
                string top = q.top();
                q.pop();
                s.push(top); 
            }
            
            return s.top();
        }
        
    }
};
