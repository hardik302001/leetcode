class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> num2;
        vector<int>res;
        while(k){
            num2.push_back(k%10);
            k = k/10;
        }
        reverse(num2.begin(),num2.end());
        int carry = 0;
        int n1 = num.size()-1;
        int n2 = num2.size()-1;
        while(carry or (n1!=-1) or (n2!=-1)){
            int tot = carry;
            if(n1>=0){
                tot = tot + num[n1];
                n1--;
            }
            if(n2>=0){
                tot = tot + num2[n2];
                n2--;
            }
            
            int last = tot%10;
            res.push_back(last);
            carry = tot/10;
           
        }
        reverse(res.begin(),res.end());
        return res;
    }
};