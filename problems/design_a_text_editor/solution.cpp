// left to keep track of chars on left side on pointer and right for right side
// initially pointer is at 0th position

/*


Always maintain the left part of string in left stack and right part of the string in right stack which are divided by the cursor

1) Add operation: Push string character by character to the left stack.
2) Deletion operation: Pop characters from the left stack and return the number of characters popped.
3) Cursor movement to left: Pop elements from left stack and push in right stack.
4) Cursor movement to right: Pop elements from right stack and push in left stack.

addText(string text) : O(n) {where n == length of text}
deleteText(int k) : O(k)
cursorLeft(int k) : O(k)
cursorRight(int k) : O(k)



LEFT STACK GOES FROM BOTOOM TO TOP
RIGHT STACK GOES FROM TOP TO BOTTOM (it is opposite),

we can also use deque..
*/

class TextEditor {
public:
    stack <char> left, right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto &c : text)
            left.push(c);
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(!left.empty() && k>0)
        {
            left.pop();
            k--;
            cnt++;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k>0)
        {
            k--;
            right.push(left.top());
            left.pop();
        }
        string ans;
        int ctr = 0;
        
        while(!left.empty() && ctr<10)
        {
            ctr++;
            ans.push_back(left.top());
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        
        for(auto &c : ans)
            left.push(c);
        return ans;
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k>0)
        {
            k--;
            left.push(right.top());
            right.pop();
        }
        string ans;
        int ctr = 0;
        
        while(!left.empty() && ctr<10)
        {
            ctr++;
            ans.push_back(left.top());
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        
        for(auto &c : ans)
            left.push(c);
        return ans;
    }
};



/*
MY TLE SOLN
class TextEditor {
public:
    
    stack<char>s;
    stack<char>ext;
    int p = 0;
    TextEditor() {
        
    }
    
    void addText(string text) {
        int extra = s.size()-p;
        while(extra--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);      
        }
        
        for(auto c: text){
            s.push(c);
            p++;
        }
       
        while(ext.size()){
            auto topa = ext.top();
            ext.pop();
            s.push(topa);
        }        

    }
    
    int deleteText(int k) {
        int c = 0;
        int extra = s.size()-p;
        while(extra--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);      
        }
        
        while(k-- and s.size()){
            s.pop();
            p--;
            c++;
        }
       
        while(ext.size()){
            auto topa = ext.top();
            ext.pop();
            s.push(topa);
        }        
        
    
        
        return c;
    }
    
    string cursorLeft(int k) {
        p = max(0 , p-k);
        // cout<<"pleft "<<p<<endl;
        string ans ;
        int posi = min(10 , p);
        
        int extra = s.size()-p;
        while(extra--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);      
        }
        while(posi--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);
            ans+=topa;
        }
       
        while(ext.size()){
            auto topa = ext.top();
            ext.pop();
            s.push(topa);
        }        
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
    
    string cursorRight(int k) {
            
        p = min(int(s.size()), p+k);
    
        string ans ;
        int extra = s.size()-p;
        while(extra--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);      
        }
        int posi = min(10 , p);
        while(posi--){
            auto topa = s.top();
            s.pop();
            ext.push(topa);
            ans+=topa;
        }
       
        while(ext.size()){
            auto topa = ext.top();
            ext.pop();
            s.push(topa);
        }        
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

*/