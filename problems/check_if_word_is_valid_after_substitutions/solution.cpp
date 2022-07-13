// as you get a, b , c in stack ,pop them

class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)   return true;
        if(s.length()%3!=0) return false;   // return false as string must ave equal no of a,b and c
        
        stack<char> sk;
        for(auto i:s)
        {
            if(i!='c')          // if char encountered is not 'c' then push
                sk.push(i);
            else
            {       // once we encounter 'c' we must have preceding  "ab"
                    // else seq is not valid
                if(sk.size()>=2)
                {
                    if(sk.top()=='b')       
                    {
                        sk.pop();
                        if(sk.top()=='a')   // now checking for 'a' to make sequence valid
                            sk.pop();
                        else
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
        return (sk.size()==0) ? true : false;        
    }
};