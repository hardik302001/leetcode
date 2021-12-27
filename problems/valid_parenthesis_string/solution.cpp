// 2 stack soln!


class Solution {
public:
    bool checkValidString(string s) {
      stack<int> open,ast;
      for(int i=0;i<s.length();i++)
      {
          if(s[i] == ')')
          {
              if(!open.empty()) open.pop();       //balance ')' by '(' 
              else if(!ast.empty()) ast.pop();    // if open is finished, we can use * and convert to open
              else return false;    // else, we have extra closed, so return false
          }
          else if(s[i] == '(')   open.push(i);
          else ast.push(i);
      }
        
    // now we have seen the case of extra closed,so we returned above!
        //what if we have extra open, we need to see them also
        
      while(!open.empty())  // so for extra opnes, we have only choice of converting * to closed
      {
          if(!ast.empty()){  // so it is necessary to have *
             if(open.top() > ast.top()) return false;   // we need to have * after open , so we need to see indexes! 
             else{              
                open.pop();
                ast.pop();
             }
          }
          else{ //else , extra *, so we are left with extra opens, so we cant do anythng, so just return false
              return false;
          }
      }
        
        
        // now we are left with extra opens ( or maybe not)
        // we convert all extra * to expty space
        // and boom , we have a valid paranthesis string
        return true;
    }
    
};