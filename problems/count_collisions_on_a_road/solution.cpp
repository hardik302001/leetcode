/*

class Solution {
public:
    int countCollisions(string s) {
        while(s.size() and s.back()=='R'){
            s.pop_back();
        }
        
        reverse(s.begin(), s.end());
        
        while(s.size() and s.back()=='L'){
            s.pop_back();
        }
        
        reverse(s.begin(), s.end());
        
        
        
        
        int n=s.size();
        int c=0;
        
        int rightcars = 0;
        for(int i = 0; i<n;i++){
            if(s[i]=='R'){
                rightcars++;
            }
            else if(s[i]=='L'){
                c+=2;
                c+=rightcars-1;
                rightcars = 0;
            }
            else{
                c+=rightcars;
                rightcars=0;
            }
        }
        
        
        return c;
    
    }
};


*/


// STACK SOLUTION

class Solution {
public:
    int countCollisions(string directions) {
    stack<char> s; int count =0;
    for(auto c:directions)
    {
        if(!s.empty() && s.top() == 'R' && c == 'L')
        {
            count+=2;
            s.pop();
            s.push('S');
        }
        else if(!s.empty() && s.top() == 'S' && c == 'L')
        {
            count+=1;
        }
       else s.push(c);
    }
    while(!s.empty())
    {
       char tmp = s.top();
       s.pop();
       if(!s.empty() && s.top() == 'S' && tmp =='L')
       {
           count++;
       }
       else if(!s.empty() && s.top() == 'R' && tmp =='S')
       {
           count++;
           s.pop();
           s.push('S');
       }
    }
     return count;   
    }
};