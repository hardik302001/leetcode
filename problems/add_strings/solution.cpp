class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string res = "";
        while(num1.size() or num2.size() or carry){
            int tot = carry;
            if(num1.length()>0){
                char ch = (num1[num1.length()-1]);
                //cout<<"cha "<<ch<<" "<<endl;
                int a = ch - '0';
                tot = tot + a;
               // cout<<"a "<<a<<endl;
                num1.pop_back();
            }
            if(num2.length()>0){
                char ch = (num2[num2.length()-1]);
             //   cout<<"chb "<<ch <<" "<<endl;
                int b = ch - '0';
                tot = tot + b;
           //     cout<<" b "<<b<<endl;
                num2.pop_back();
            }
            //cout<<tot<<" ";
            carry = tot/10;
            int last = tot%10;
            
            res = res + to_string(last);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};