class Solution {
public:
    int myAtoi(string str)
    {
        int sign =1;
        long int result=0;
        int i;
        int s=str.size();
        for(i=0;i<s;i++)
        {
            if(str[i]!=' ')
                break;
        }
        
        
        if(str[i]=='+'||str[i]=='-'){
            sign= str[i]=='-' ?-1:1;
            i = i +1;  //move to next position after sign only if we are given iwth sign, else we dont need to move one posi ahead
        }
        
        
        while(i<s && isdigit(str[i]))
        {
            result= result*10 + (str[i++]-'0');
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result*sign <= INT_MIN) return INT_MIN;
        } 
        return result*sign;
    }
};