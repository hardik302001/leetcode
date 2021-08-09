class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans = "";
        while(num1.size() or num2.size() or carry){
            int temp = 0;
            if(num1.size()){
                temp += (num1[num1.size()-1]-'0');
                num1.pop_back();
            }
            if(num2.size()){
                temp += (num2[num2.size()-1]-'0');
                num2.pop_back();
            }
            
            temp += carry;
            carry = temp/10;
            cout<<temp<<" ";
            ans = to_string(temp%10) + ans;
        }
    
        return ans;
    }
    
    
};