class Solution {
public:
    string removeDigit(string s, char digit) {
        int n = s.length();
        int f = 0;
        long int last = s.find_last_of(digit);
        for(int i=0; i<n; i++)
        {
            if(s[i] == digit)
            {
                if(i != last)
                {
                    if(s[i+1] > s[i])
                    {
                        s.erase(i, 1);
                        f = 1;
                        break;
                    }
                }
            }
        }
        
        if(!f) s.erase(last, 1);
        return s;
    }
};