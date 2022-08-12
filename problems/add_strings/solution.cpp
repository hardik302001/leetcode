class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string res = "";
        
        while(num1.size() or num2.size() or carry){
            int tot = carry;
            if(num1.length()>0){
                char ch = (num1[num1.length()-1]);
             
                int a = ch - '0';
                tot = tot + a;
            
                num1.pop_back();
            }
            if(num2.length()>0){
                char ch = (num2[num2.length()-1]);
     
                int b = ch - '0';
                tot = tot + b;
           
                num2.pop_back();
            }
           
            carry = tot/10;
            int last = tot%10;
            
            res = res + to_string(last);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};